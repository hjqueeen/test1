#include "mybinarytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LEFT "LEFT"
#define RIGHT "RIGHT"

//https://velog.io/@gogori6565/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EC%9D%B4%EC%A7%84%ED%8A%B8%EB%A6%AC

TreeNode *createNode(int data) {
    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

TreeNode *addNode(TreeNode *tree, int value) {
    if (tree == NULL) {
        return createNode(value);
    }
    if (tree->data > value) {
        tree->left = addNode(tree->left, value);
    } else if (tree->data < value) {
        tree->right = addNode(tree->right, value);
    }
    return tree;
}

void inorderTraversal(TreeNode *tree) {
    if (tree != NULL) {
        inorderTraversal(tree->left);
        printf("%d, ", tree->data);
        inorderTraversal(tree->right);
    }
}

void preorderTraversal(TreeNode *tree) {
    if (tree != NULL) {
        printf("%d, ", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void postorderTraversal(TreeNode *tree) {
    if (tree != NULL) {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d, ", tree->data);
    }
}

TreeNode *searchValue(TreeNode *tree, int value) {
    if (tree == NULL || tree->data == value) {
        return tree;
    }
    if (tree->data > value) {
        searchValue(tree->left, value);
    } else {
        searchValue(tree->right, value);
    }
}

void startTree() {
    TreeNode *tree = NULL;
    tree = addNode(tree, 40);
    addNode(tree, 20);
    addNode(tree, 60);
    addNode(tree, 10);
    addNode(tree, 30);
    addNode(tree, 50);
    addNode(tree, 70);
    addNode(tree, 5);
    addNode(tree, 15);
    addNode(tree, 25);
    addNode(tree, 35);
    addNode(tree, 45);
    addNode(tree, 55);
    addNode(tree, 65);
    addNode(tree, 75);

    inorderTraversal(tree);
    printf("\n");
    preorderTraversal(tree);
    printf("\n");
    postorderTraversal(tree);
    printf("\n");

    TreeNode *searched = searchValue(tree, 35);
    if (searched != NULL) {
        printf("Value: %d \n", searched->data);
    } else {
        printf("No value\n");
    }
   searched = searchValue(tree, 32);
    if (searched != NULL) {
        printf("Value: %d \n", searched->data);
    } else {
        printf("No value\n");
    }
}