#ifndef TREEFLAGS_H_
# define TREEFLAGS_H_

/*!
 * \class TreeFlags treeflags.h "treeflags.h"
 * \brief This class manage the \ref TreeFlag enumeration
 *
 * It add all the bitwise operator
 */
class TreeFlags
{
public:
    enum TreeFlag
    {
        NoNodeFlags             = 0x00,
        NodeNeverHasChildren    = 0x01
    };

public:
    TreeFlags(TreeFlags::TreeFlag flag);

    TreeFlags operator~() const;
    TreeFlags operator&(const TreeFlags::TreeFlag &flag) const;
    TreeFlags operator|(const TreeFlags::TreeFlag &flag) const;
    TreeFlags operator^(const TreeFlags::TreeFlag &flag) const;
    TreeFlags& operator&=(const TreeFlags::TreeFlag &flag);
    TreeFlags& operator|=(const TreeFlags::TreeFlag &flag);
    TreeFlags& operator^=(const TreeFlags::TreeFlag &flag);

    operator bool() const;
    bool operator!() const;

private:
    TreeFlags(unsigned long flags);

private:
    unsigned long _flags;
};

/**
 * \enum TreeFlags::TreeFlag
 * You can use this enum to specify some attribute to a specific node\n
 * Flag can be added by using the OR (|) operator
 *
 * \var TreeFlags::TreeFlag TreeFlags::NoNodeFlags
 * This special value mean that the node soed not have any flag
 *
 * \var TreeFlags::TreeFlag TreeFlags::NodeNeverHasChildren
 * This flag specify that the TreeNode::addChild() and TreeNode::moveChild() will not have any effect and will return \b false immediately
 */

/*!
 * \fn TreeFlags::TreeFlags(TreeFlags::TreeFlag flag)
 * \brief Default constructor
 *
 * \param flag  The initial flag you want put in
 */

#endif /* !TREEFLAGS_H_ */
