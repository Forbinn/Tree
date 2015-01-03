/*
** main.cpp for Tree in /home/leroy_v/Perso/Tree
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sun Dec 14 15:31:01 2014 vincent leroy
** Last update Sat Jan 03 21:08:23 2015 vincent leroy
*/

#include <iostream>

#include "treenode.h"

#define RootNodeType    (TreeNode::UserType + 1)
#define LeafNodeType    (TreeNode::UserType + 2)

static TreeNode* createLeaf(const std::string &name, TreeNode *parent = 0)
{
    TreeNode* leaf = new TreeNode(name, LeafNodeType, parent);
    leaf->setFlags(TreeFlags::NodeNeverHasChildren);

    return leaf;
}

static void aff(TreeNode *node)
{
    std::cout << node->name() << std::endl;
}

class test
{
public:
    test() :
        _i(0)
    {}

    void aff(TreeNode *node) const
    {
        std::cout << node->name() << std::endl;
    }

    void countLeaf(TreeNode *node)
    {
        if (node->isLeaf())
            ++_i;
    }

    inline int i() const { return _i; }

    static void display(TreeNode *node)
    {
        std::cout << node->name() << std::endl;
    }

private:
    int _i;
};

int main()
{
    TreeNode *root = new TreeNode("Root", RootNodeType);

    TreeNode *node1 = new TreeNode("Node 1", TreeNode::Type, root);
    TreeNode *node2 = new TreeNode("Node 2", TreeNode::Type, root);
    TreeNode *node3 = new TreeNode("Node 3", TreeNode::Type, node1);
    TreeNode *node4 = new TreeNode("Node 4", TreeNode::Type, node2);
    TreeNode *node5 = new TreeNode("Node 5", TreeNode::Type, node2);

    createLeaf("Leaf 1", root);
    createLeaf("Leaf 2", node1);
    createLeaf("Leaf 3", node3);
    createLeaf("Leaf 4", node3);
    createLeaf("Leaf 5", node3);
    createLeaf("Leaf 6", node4);
    createLeaf("Leaf 7", node4);

    test t;
    std::cout << "Iter with function" << std::endl;
    root->iter(&aff);
    std::cout << std::endl << "Iter with static function" << std::endl;
    root->iter(&test::display);
    std::cout << std::endl << "Iter with const method" << std::endl;
    root->iter(&test::aff, &t);
    std::cout << std::endl << "Iter with method" << std::endl;
    root->iter(&test::countLeaf, &t);
    std::cout << "Number of leaf in the tree: " << t.i() << std::endl;

    /*std::list<TreeNode*> list = root->findAll("Leaf 1");
    std::list<TreeNode*>::const_iterator itr;

    std::cout << "Find " << list.size() << " item(s)" << std::endl;
    for (itr = list.begin(); itr != list.end(); ++itr)
        std::cout << (*itr)->name() << std::endl;

    std::cout << std::endl;

    TreeNode *node = root->findOne("Leaf 1");
    std::cout << "Find " << (node ? "one " : "zero ") << "node" << std::endl;
    if (node)
        std::cout << node->name() << std::endl;*/

    delete root;

    (void)node5;
    return 0;
}
