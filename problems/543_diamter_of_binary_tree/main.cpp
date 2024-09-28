#include <iostream>
#include "../../includes/binary_tree.h"
#include <stack>

class Solution{
    public:
      	

};

int main(){
    Solution* solution = new Solution();

    BinaryTree* binary_tree = new BinaryTree(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);

    binary_tree->root->left = two;
    binary_tree->root->right = three;

    two->left = four;
    two->right = five;
    binary_tree->traverse(TraversalType::IN_ORDER);

    int diameter = solution->diameterOfBinaryTree(binary_tree->root);
    return 0;
}
