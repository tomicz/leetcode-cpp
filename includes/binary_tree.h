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

enum TraversalType{
    LEVEL_ORDER,
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

class BinaryTree{
    public:
        TreeNode* root;
        int size;

        BinaryTree(int value);

        TreeNode* insert(int value);
        TreeNode* find(int value);
        void traverse(TraversalType type);

    private:
        void level_order_traversal();

};
#endif
