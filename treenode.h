#ifndef TREENODE_H
#define TREENODE_H

#include <set>
#include <string>

#include "treeflags.h"

/*!
 * \class TreeNode treenode.h "treenode.h"
 * \brief This class represent a node in a tree structure
 *
 * The TreeNode can either be the root node or a simple node or a leaf node\n
 * You can subclass this class if you add some data in this one\n
 * You can distinguish your own class from the TreeNode class by using the TreeType enum
 */
class TreeNode
{
public:
    enum TreeType
    {
        Type,
        UserType
    };

public:
    explicit TreeNode(int type = TreeNode::Type, TreeNode *parent = 0);
    explicit TreeNode(const std::string &name, int type = TreeNode::Type, TreeNode *parent = 0);
    virtual ~TreeNode();

    inline const std::string& name() const { return _name; }
    inline void setName(const std::string &name) { _name = name; }

    inline int type() const { return _type; }

    inline TreeFlags flags() const { return _flags; }
    void setFlags(TreeFlags flags);

    bool addChild(TreeNode *child);
    bool moveChild(TreeNode *child);
    bool removeChild(TreeNode *child);

    inline const std::set<TreeNode*>& children() const { return _children; }
    const TreeNode* findChild(const std::string &name) const;
    const TreeNode* findChildRecursively(const std::string &data, int maxDepth = -1) const;
    TreeNode* findChild(const std::string &data);
    TreeNode* findChildRecursively(const std::string &data, int maxDepth = -1);

    inline const TreeNode* parent() const { return _parent; }
    inline TreeNode* parent() { return _parent; }

    inline bool isRoot() const { return _children.empty(); }
    inline bool isLeaf() const { return _parent == NULL; }

    int depth() const;

private:
    void _childDestroyed(TreeNode *child);

private:
    std::string _name;

    int _type;
    TreeFlags _flags;

    TreeNode *_parent;
    std::set<TreeNode*> _children;
};

/*!
 * \enum TreeNode::TreeType
 * This enum is used to describe the type of the current node if you subclass it
 *
 * \var TreeNode::TreeType TreeNode::Type
 * Default type used by this library
 *
 * \var TreeNode::TreeType TreeNode::UserType
 * The value for subclass begin at this value
 */

/*!
 * \fn TreeNode::TreeNode(TreeNode::TreeType type = TreeNode::Type, TreeNode *parent = 0)
 * \brief Default constructor
 *
 * If the parent is not null then the current node is added to it\n
 * With this constructor the name is empty
 *
 * \param type      The type of the current node
 * \param parent    The parent of the current node
 */

/*!
 * \fn TreeNode::TreeNode(const std::string &name, TreeNode::TreeType type = TreeNode::Type, TreeNode *parent = 0)
 * \brief Constructor with the name of the node
 *
 * If the parent is not null then the current node is added to it
 *
 * \param name      The name of the node
 * \param type      The type of the current node
 * \param parent    The parent of the current node
 */

/*!
 * \fn TreeNode::~TreeNode()
 * \brief Node destructor
 *
 * If the parent is not null then its _childDestroyed method is called\n
 * All the children of the current destroyed node are also deleted
 */

/*!
 * \fn const std::string& TreeNode::name() const
 * \brief Getter for the name of the node
 *
 * \return The name of the current node
 *
 * \see TreeNode::setName()
 */

/*!
 * \fn void TreeNode::setName(const std::string &name)
 * \brief Setter for the name of the node
 *
 * \param name  The new name for this node
 *
 * \see TreeNode::name()
 */

/*!
 * \fn TreeNode::TreeType TreeNode::type() const
 * \brief Getter for the type of the node
 *
 * \return The type of the current node
 */

/*!
 * \fn TreeFlags TreeNode::flags() const
 * \brief Getter for the flags of the node
 *
 * \return The flags of the current node
 *
 * \see TreeNode::setFlags()
 */

/*!
 * \fn void TreeNode::setFlags(TreeFlags flags)
 * \brief Setter for the flags of the node
 *
 * This method will erase all the previous flag\n
 * If the current node have children and in the new flags the flag
 * TreeFlags::NodeNeverHasChildren is present then \b all the children are remove but \b not deleted
 *
 * \param flags The new flags
 *
 * \see TreeNode::flags()
 */

/*!
 * \fn bool TreeNode::addChild(TreeNode *child)
 * \brief Method to add a child to the current node
 *
 * If the TreeFlags::NodeNeverHasChildren flag is set then this method will immediately return false\n
 * This method will also return false if the child has already a parent (TreeNode::moveChild())\n
 * The parent of the child is then set to this node
 *
 * \param child The new child of this node
 *
 * \return True if the chils has been added
 */

/*!
 * \fn bool TreeNode::moveChild(TreeNode *child)
 * \brief This method add a child to this node even if it already has a parent
 *
 * If the TreeFlags::NodeNeverHasChildren flag is set then this method will immediately return false\n
 * If the child has already a parent then it is remove from it and added to this node\n
 * The parent of the child is then set to this node
 *
 * \param child The new child of this node
 *
 * \return True if the chils has been added
 */

/*!
 * \fn bool TreeNode::removeChild(TreeNode *child)
 * \brief Methd to remove a child from this node
 *
 * This method will \b not delete the child but only remove it from the internal list of children
 *
 * \param child The child you want remove
 *
 * \return True if the child has been removed
 */

/*!
 * \fn const std::set<TreeNode*>& TreeNode::children() const
 * \brief Method to get the list of all the children of this node
 *
 * \return All the children
 */

/*!
 * \fn const TreeNode* TreeNode::findChild(const std::string &name) const
 * \brief Method to find a child on this node and this node only
 *
 * If multiple node have the same name the first one is returned\n
 * This will be improved in future version
 *
 * \param name The name of the node you want retreived
 *
 * \return The node with the name \a name or NULL if not found
 */

/*!
 * \fn const TreeNode* TreeNode::findChildRecursively(const std::string &name, int maxDepth) const
 * \brief Method to find a child with is name in this node and all this children recursively
 *
 * If multiple node have the same name the first one is returned\n
 * This will be improved in future version
 *
 * \param name      The name of the node you want retreived
 * \param maxDepth  The maximum level where you want search (-1 for infinite depth)
 *
 * \return The node with the name \a name or NULL if not found
 */

/*!
 * \overload TreeNode* TreeNode::findChild(const std::string &name)
 */

/*!
 * \overload TreeNode* TreeNode::findChildRecursively(const std::string &name, int maxDepth)
 */

/*!
 * \fn const TreeNode* TreeNode::parent() const
 * \brief Method to get the parent of the node
 *
 * The parent can be NULL
 *
 * \return The parent of the node
 *
 * \see TreeNode::isRoot()
 */

/*!
 * \overload TreeNode* TreeNode::parent()
 */

/*!
 * \fn bool TreeNode::isLeaf() const
 * \brief Method to check if this node has children or not
 *
 * \return True if the node has children
 *
 * \see TreeNode::isRoot()
 */

/*!
 * \fn bool TreeNode::isRoot() const
 * \brief Method to check if the node has a parent or not
 *
 * \return True if the node has a parent
 *
 * \see TreeNode::isLeaf()
 */

/*!
 * \fn int TreeNode::depth() const
 * \brief Method to calculate the depth of the tree
 *
 * This method return the \b maximum depth of the tree
 *
 * \return The depth of the tree
 */

#endif // TREENODE_H
