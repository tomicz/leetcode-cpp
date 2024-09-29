#include <iostream>
#include "../../includes/binary_tree.h"

class Solution{
    public:
        int result = 0;
        int diameterOfBinaryTree(TreeNode* root) {
            traverse_tree(root);
            return result;
        }

        int traverse_tree(TreeNode* current){
            if(current == nullptr) return 0;
            int left_node = traverse_tree(current->left);
            int right_node = traverse_tree(current->right);
            result = std::max(result, left_node + right_node);
            return 1 + std::max(left_node, right_node);
        }
};

int main(){
    Solution solution;

    BinaryTree* binary_tree = new BinaryTree(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    binary_tree->root->left = two;
    binary_tree->root->right = three;
    two->left = four;
    two->right = five;

    int diameter = solution.diameterOfBinaryTree(binary_tree->root);
    std::cout << "diameter: "<< diameter << std::endl;
    return 0;
}
