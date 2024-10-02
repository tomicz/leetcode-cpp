#include <ios>
#include <iostream>
#include "../../includes/binary_tree.h"

class Solution{
    public:
        bool is_subtree(TreeNode* s, TreeNode* t){
            if(t == nullptr) return true;
            if(s == nullptr) return false;
            if(is_same_tree(s, t)) return true;
            return is_subtree(s->left, t) || is_subtree(s->right, t);
        }

        bool is_same_tree(TreeNode* s, TreeNode* t){
            if(s == nullptr && t == nullptr) return true;
            if(s != nullptr && t != nullptr && s->value == t->value){
                return is_same_tree(s->left, t->left) && is_same_tree(s->right, t->right);
            }

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
    std::cout << "has subtree: " << is_sub << std::endl;
    return 0;
}
