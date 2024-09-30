#include <iostream>
#include <stack>
#include "../../includes/binary_tree.h"

class Solution{
    public:
        bool is_same_tree(TreeNode* p, TreeNode* q){
            if(p == nullptr && q == nullptr) return true;
            if(p == nullptr || q == nullptr) return false;
            if(p->value != q->value) return false;

            return is_same_tree(p->left, q->left) && is_same_tree(p->right, q->right);
        }
};

int main(){
    Solution solution;
    BinaryTree* binary_tree = new BinaryTree(1);
    BinaryTree* binary_tree1 = new BinaryTree(1);
    TreeNode* p = binary_tree->root;
    TreeNode* p1 = new TreeNode(2);
    TreeNode* p2 = new TreeNode(3);
    p->left = p1;
    p->right = p2;
    TreeNode* q = binary_tree1->root;
    TreeNode* q1 = new TreeNode(2);
    TreeNode* q2 = new TreeNode(3);
    q->left = q1;
    q->right = q2;
    bool is_same = solution.is_same_tree(p, q);
    std::cout << std::boolalpha;
    std::cout << "is same tree: " << is_same << std::endl;
    return 0;
}
