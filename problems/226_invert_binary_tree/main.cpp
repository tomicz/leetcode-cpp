#include <iostream>
#include <stack>
#include "../../includes/binary_tree.h"

class Solution{
    public:
        TreeNode* invertTree(TreeNode* root){
            std::stack<TreeNode*> s;
            TreeNode* current_node = root;
            while(!s.empty() || current_node != nullptr){
                while(current_node != nullptr){
                    s.push(current_node);
                    TreeNode* temp_node = current_node->right;
                    current_node->right = current_node->left;
                    current_node->left = temp_node; 
                    current_node = current_node->left;
                }
                current_node = s.top();
                s.pop();
                current_node = current_node->right;
            }
            return root; 
        }
};

int main(){
    Solution solution;
    BinaryTree* binary_tree = new BinaryTree(4);
    binary_tree->insert(2);
    binary_tree->insert(1);
    binary_tree->insert(3);
    binary_tree->insert(7);
    binary_tree->insert(6);
    binary_tree->insert(9);
    binary_tree->traverse(TraversalType::IN_ORDER);
    TreeNode* node = solution.invertTree(binary_tree->root);
    binary_tree->root = node;
    binary_tree->traverse(TraversalType::IN_ORDER);
    return 0;
}
