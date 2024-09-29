#include <iostream>
#include "../../includes/binary_tree.h"

class Solution{
    public:
        bool is_balanced(TreeNode* root){
            if(root == nullptr) return true;
            if(get_tree_height(root) == -1) return false;
            return true;
        }

        int get_tree_height(TreeNode* root){
            if(root == nullptr) return 0;
            int l_node = get_tree_height(root->left);
            if(l_node == -1) return -1;
            int r_node = get_tree_height(root->right);
            if(r_node == -1) return -1;
            if(abs(l_node - r_node) > 1) return -1; 
            return std::max(l_node, r_node) + 1;
        }
};

int main(){
    Solution solution;
    
    // Example 1
    std::cout << "case 1" << std::endl;
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

    // Example 2
    std::cout << "case 2" << std::endl;
    BinaryTree* binary_tree2 = new BinaryTree(1);
    TreeNode* root2 = binary_tree2->root; 
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(4);

    root2->left = node2;
    root2->right = node3;
    root2->left->left= node4;
    root2->left->right = node5;
    root2->left->left->left = node6;
    root2->left->left->right = node7;
    bool balanced1 = solution.is_balanced(root2);

    std::cout << std::boolalpha;
    std::cout << "is balanced: " << balanced << std::endl;
    std::cout << "is balanced: " << balanced1 << std::endl;

    return 0;
}
