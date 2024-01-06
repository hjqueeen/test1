//
// Created by 518597 on 06.01.2024.
//

#ifndef TESTVORBEREITEN_MYBINARYTREE_H
#define TESTVORBEREITEN_MYBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int data);

TreeNode *addNode(TreeNode *tree, int value);

void inorderTraversal(TreeNode *tree);

void startTree();

#endif //TESTVORBEREITEN_MYBINARYTREE_H
