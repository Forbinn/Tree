/*
** main.cpp for Tree in /home/leroy_v/Perso/Tree
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sun Dec 14 15:31:01 2014 vincent leroy
** Last update Wed Dec 24 15:16:57 2014 vincent leroy
*/

#include <iostream>

#include "treenode.h"

#define RootNodeType    (TreeNode::UserType + 1)
#define LeafNodeType    (TreeNode::UserType + 2)

int main()
{
    TreeNode *root = new TreeNode("Root", RootNodeType);
    TreeNode *leaf1 = new TreeNode("Leaf 1", LeafNodeType, root);
    leaf1->setFlags(TreeFlags::NodeNeverHasChildren);

    TreeNode *node1 = new TreeNode("Node 1");

    std::cout << "This should fail: " << leaf1->addChild(node1) << std::endl;
    std::cout << "This should pass: " << root->addChild(node1) << std::endl;
    return 0;
}
