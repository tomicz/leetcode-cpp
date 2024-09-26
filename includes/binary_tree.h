#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value){
       this->value = value;         
       left = nullptr;
       right = nullptr;
    }
};

class BinaryTree{
    public:
        TreeNode* root;
        int size;

        BinaryTree(int value);

        TreeNode* insert(int value);
        TreeNode* find(int value);
        void traverse();
};

#endif
