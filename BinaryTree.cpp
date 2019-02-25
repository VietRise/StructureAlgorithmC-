#include "BinaryTree.h"
#include <math.h>

using namespace std;

TreeNode::TreeNode(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}


BinaryTree::~BinaryTree()
{
}

BinaryTree::BinaryTree()
{
    this->root = nullptr;
}

BinaryTree::BinaryTree(TreeNode* root)
{
    this->root = root;
}

BinaryTree* BinaryTree::create()
{
    BinaryTree* binaryTree = new BinaryTree();
    return binaryTree;
}

BinaryTree* BinaryTree::createMinimalBTS(int* array, int size)
{
    BinaryTree* binaryTree = new BinaryTree(BinaryTree::insertMinimalBTS(array, 0, size - 1));
    return binaryTree;
}

void BinaryTree::insert(int data)
{
    if(root)
    {
        this->insert(data, root);
    }
    else
    {
        root = new TreeNode(data);
    }
}

TreeNode* BinaryTree::search(int data)
{
    return search(data, root);
}

void BinaryTree::inOderPrintf()
{
    cout << "InOderPrintf" << endl;
    inOderPrintf(root);
    cout << endl;
}

void BinaryTree::preOderPrintf()
{
    cout << "PreOderPrintf" << endl;
    preOderPrintf(root);
    cout << endl;
}

void BinaryTree::postOderPrintf()
{
    cout << "PostOderPrintf" << endl;
    postOderPrintf(root);
    cout << endl;
}

void BinaryTree::levelOderPrintf()
{
    cout << "LevelOderPrintf" << endl;
    levelOderPrintf(root);
    cout << endl;
}

int BinaryTree::height()
{
    return height(root);
}

bool BinaryTree::isBalance()
{
    return minDepth(root) == maxDepth(root);
}

void BinaryTree::insert(int data, TreeNode* root)
{
    if(data < root->data)
    {
        if(root->left)
            this->insert(data, root->left);
        else
            root->left = new TreeNode(data);
    }
    else
    {
        if(root->right)
            this->insert(data, root->right);
        else
            root->right = new TreeNode(data);
    }
}

TreeNode* BinaryTree::search(int data, TreeNode* root)
{
    if(root)
    {
        if(data == root->data)
            return root;
        else if (data < root->data)
            search(data, root->left);
        else 
            search(data, root->right);
        
    }
    return nullptr;    
}

void BinaryTree::inOderPrintf(TreeNode* root)
{
    if(root)
    {
        inOderPrintf(root->left);
        cout << root->data << " ; ";
        inOderPrintf(root->right);
    }
}

void BinaryTree::preOderPrintf(TreeNode* root)
{
    if(root)
    {
        cout << root->data << " ; ";
        preOderPrintf(root->left);
        preOderPrintf(root->right);
    }
}

void BinaryTree::postOderPrintf(TreeNode* root)
{
    if(root)
    {
        postOderPrintf(root->left);
        postOderPrintf(root->right);
        cout << root->data << " ; ";
    }
}

void BinaryTree::levelOderPrintf(TreeNode* root)
{
    int height = this->height(root);
    for(int i = 1; i <= height; i++)
    {
        givenLevelPrintf(root, i);
        cout << endl;
    }
}

void BinaryTree::givenLevelPrintf(TreeNode* root, int level)
{
    if(!root)
        return;
    if(level == 1)
        cout << root->data << " ; ";
    else if (level > 1)
    {
        givenLevelPrintf(root->left, level - 1);
        givenLevelPrintf(root->right, level - 1);
    }
}

int BinaryTree::height(TreeNode* root)
{
    if(!root)
        return 0;
    else 
    {
        int lHeight = height(root->left);
        int rHeight = height(root->right);

        if(lHeight > rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }
}

int BinaryTree::minDepth(TreeNode* root)
{
    if(!root)
        return 0;
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}

int BinaryTree::maxDepth(TreeNode* root)
{
    if(!root)
        return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

TreeNode* BinaryTree::insertMinimalBTS(int* array, int start, int end)
{
    if(end < start)
        return nullptr;

    int mid = (end - start)/2;
    TreeNode* node = new TreeNode(array[mid]);
    node->left = insertMinimalBTS(array, start, mid - 1);
    node->right = insertMinimalBTS(array, mid + 1, end);
    return node;
}