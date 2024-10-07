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

enum TraversalTypeRecursive{
    RECURSIVE_PRE_ORDER,
    RECURSIVE_IN_ORDER,
    RECURSIVE_POST_ORDER
};

class BinaryTree{
    public:
        TreeNode* root;
        int size;

        BinaryTree(int value);

        TreeNode* insert(int value);
        TreeNode* find(int value);
        void traverse(TraversalType type);
        void traverse_recursive(TraversalTypeRecursive type);
        int max_depth();

    private:
        void level_order_traversal();
        void in_order_traversal();
        void pre_order_traversal();
        void pre_order_traversal_recursive(TreeNode* root);
        void in_order_traversal_recursive(TreeNode* root);
        void post_order_traversal_recursive(TreeNode* root);
        int max_depth(TreeNode* root);

};
#endif
