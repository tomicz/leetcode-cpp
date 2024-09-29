#include <iostream>
#include "../../includes/binary_tree.h"

class Solution{
    public:
        bool is_balanced(TreeNode* root){
            
            return false;
        }
};

int main(){
    Solution solution;
    BinaryTree* binary_tree = new BinaryTree(3);
    TreeNode* root = binary_tree->root;
    TreeNode* nodeA = new TreeNode(9);
    TreeNode* nodeB = new TreeNode(20);
    TreeNode* nodeC = new TreeNode(15);
    TreeNode* nodeD = new TreeNode(7);
    root->left = nodeA;
    root->right = nodeB;
    root->right->left = nodeC;
    root->right->right = nodeD;
    bool balanced = solution.is_balanced(root);
    binary_tree->traverse_recursive(TraversalTypeRecursive::RECURSIVE_PRE_ORDER);
    std::cout << std::boolalpha;
    std::cout << "is balanced: " << balanced << std::endl;

    return 0;
}
