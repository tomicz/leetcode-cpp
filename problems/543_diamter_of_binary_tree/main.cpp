#include <iostream>
#include "../../includes/binary_tree.h"
#include <stack>

class Solution{
    public:
        int result = 0;
        int diameterOfBinaryTree(TreeNode* root) {
            dfs(root);
            return result;
        }
                
        int dfs(TreeNode* current){
            if(current == nullptr) return 0;
            int left = dfs(current->left);
            int right = dfs(current->right);
            result = std::max(result, left + right);
            return 1 + std::max(left, right);
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
