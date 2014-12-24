#include "treenode.h"

TreeNode::TreeNode(int type, TreeNode *parent) :
    _name(),
    _type(type),
    _flags(TreeFlags::NoNodeFlags),
    _parent(NULL),
    _children(),
    _isDestroy(false)
{
    if (parent != NULL)
        _parent = parent->addChild(this) ? parent : NULL;
}

TreeNode::TreeNode(const std::string &name, int type, TreeNode *parent) :
    _name(name),
    _type(type),
    _flags(TreeFlags::NoNodeFlags),
    _parent(NULL),
    _children(),
    _isDestroy(false)
{
    if (parent != NULL)
        _parent = parent->addChild(this) ? parent : NULL;
}

TreeNode::~TreeNode()
{
    _isDestroy = true;

    if (_parent != NULL && !_parent->_isDestroy)
        _parent->_childDestroyed(this);

    std::set<TreeNode*>::const_iterator itr;
    for (itr = _children.begin(); itr != _children.end(); ++itr)
        delete *itr;
}

void TreeNode::setFlags(TreeFlags flags)
{
    _flags = flags;

    if (_flags & TreeFlags::NodeNeverHasChildren)
        _children.clear();
}

bool TreeNode::addChild(TreeNode *child)
{
    if (_flags & TreeFlags::NodeNeverHasChildren)
        return false;
    else if (child == NULL || child->_parent != NULL)
        return false;

    child->_parent = this;
    _children.insert(child);
    return true;
}

bool TreeNode::moveChild(TreeNode *child)
{
    if (_flags & TreeFlags::NodeNeverHasChildren)
        return false;
    else if (child == NULL)
        return false;

    if (child->_parent != NULL)
        child->_parent->removeChild(child);
    child->_parent = this;
    _children.insert(child);
    return true;
}

bool TreeNode::removeChild(TreeNode *child)
{
    return _children.erase(child);
}

const TreeNode* TreeNode::findChild(const std::string &name) const
{
    std::set<TreeNode*>::const_iterator itr;
    for (itr = _children.begin(); itr != _children.end(); ++itr)
    {
        const TreeNode *child = *itr;
        if (child->_name == name)
            return child;
    }

    return NULL;
}

const TreeNode* TreeNode::findChildRecursively(const std::string &name, int maxDepth) const
{
    if (maxDepth == 0)
        return NULL;

    std::set<TreeNode*>::const_iterator itr;
    for (itr = _children.begin(); itr != _children.end(); ++itr)
    {
        const TreeNode *child = *itr;
        if (child->_name == name)
            return child;

        const TreeNode *res = child->findChildRecursively(name, maxDepth - 1);
        if (res != NULL)
            return res;
    }

    return NULL;
}

TreeNode* TreeNode::findChild(const std::string &name)
{
    std::set<TreeNode*>::iterator itr;
    for (itr = _children.begin(); itr != _children.end(); ++itr)
    {
        TreeNode *child = *itr;
        if (child->_name == name)
            return child;
    }

    return NULL;
}

TreeNode* TreeNode::findChildRecursively(const std::string &name, int maxDepth)
{
    if (maxDepth == 0)
        return NULL;

    std::set<TreeNode*>::iterator itr;
    for (itr = _children.begin(); itr != _children.end(); ++itr)
    {
        TreeNode *child = *itr;
        if (child->_name == name)
            return child;

        TreeNode *res = child->findChildRecursively(name, maxDepth - 1);
        if (res != NULL)
            return res;
    }

    return NULL;
}

int TreeNode::depth() const
{
    if (_children.empty())
        return 0;

    int max = 0;
    std::set<TreeNode*>::const_iterator itr;
    for (itr = _children.begin(); itr != _children.end(); ++itr)
        max = std::max(max, (*itr)->depth());

    return max + 1;
}

void TreeNode::_childDestroyed(TreeNode *child)
{
    removeChild(child);
}
