/*
** main.cpp for Tree in /home/leroy_v/Perso/Tree
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sun Dec 14 15:31:01 2014 vincent leroy
** Last update Wed Dec 31 13:11:33 2014 vincent leroy
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

int main()
{
    TreeNode *root = new TreeNode("Root", RootNodeType);

    TreeNode *node1 = new TreeNode("Node 1", TreeNode::Type, root);
    TreeNode *node2 = new TreeNode("Node 2", TreeNode::Type, root);
    TreeNode *node3 = new TreeNode("Node 3", TreeNode::Type, node1);
    TreeNode *node4 = new TreeNode("Node 4", TreeNode::Type, node2);
    TreeNode *node5 = new TreeNode("Node 5", TreeNode::Type, node2);

    createLeaf("Leaf 2", root);
    createLeaf("Leaf 2", node1);
    createLeaf("Leaf 3", node3);
    createLeaf("Leaf 1", node3);
    createLeaf("Leaf 1", node3);
    createLeaf("Leaf 6", node4);
    createLeaf("Leaf 7", node4);

    std::list<TreeNode*> list = root->findAll("Leaf 1");
    std::list<TreeNode*>::const_iterator itr;

    std::cout << "Find " << list.size() << " item(s)" << std::endl;
    for (itr = list.begin(); itr != list.end(); ++itr)
        std::cout << (*itr)->name() << std::endl;

    std::cout << std::endl;

    TreeNode *node = root->findOne("Leaf 1");
    std::cout << "Find " << (node ? "one " : "zero ") << "node" << std::endl;
    if (node)
        std::cout << node->name() << std::endl;

    delete root;

    (void)node5;
    return 0;
}
