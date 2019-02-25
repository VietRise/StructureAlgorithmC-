#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    public:
        TreeNode(int data);
};

class BinaryTree
{
    public:
        TreeNode* root;

    public:
        ~BinaryTree();
        BinaryTree();
        BinaryTree(TreeNode* root);
        static BinaryTree* create();
        static BinaryTree* createMinimalBTS(int* array, int size);
        void insert(int data);
        TreeNode* search(int data);
        void inOderPrintf();    // DFT
        void preOderPrintf();   // DFT
        void postOderPrintf();  // DFT
        void levelOderPrintf(); // BFT
        int height();
        bool isBalance();
    
    private:
        void insert(int data, TreeNode* root);
        TreeNode* search(int data, TreeNode* root);
        void inOderPrintf(TreeNode* root);
        void preOderPrintf(TreeNode* root);
        void postOderPrintf(TreeNode* root);
        void levelOderPrintf(TreeNode* root);
        void givenLevelPrintf(TreeNode* root, int level);
        int height(TreeNode* root);
        int minDepth(TreeNode* root);
        int maxDepth(TreeNode* root);
        static TreeNode* insertMinimalBTS(int* array, int start, int end);
};

#endif