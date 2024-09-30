#include <ios>
#include <iostream>
#include "../../includes/binary_tree.h"

class Solution{
    public:
        bool is_subtree(TreeNode* root, TreeNode* sub_root){

            return false;
        }
};

int main(){
    BinaryTree* binary_tree = new BinaryTree(3);
    TreeNode* root = binary_tree->root;
    TreeNode* nodeA = new TreeNode(4);
    TreeNode* nodeB = new TreeNode(5);
    TreeNode* nodeC = new TreeNode(1);
    TreeNode* nodeD = new TreeNode(2);
    root->left = nodeA;
    root->right = nodeB;
    root->left->left = nodeC;
    root->left->right = nodeD;
    Solution solution;
    bool is_sub = solution.is_subtree(root, root->left);
    std::cout << std::boolalpha;
    std::cout << "is subtree: " << is_sub << std::endl;
    return 0;
}
