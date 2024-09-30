#include <iostream>
#include "../../includes/binary_tree.h"

class Solution{
    public:
        bool is_same_tree(TreeNode* p, TreeNode* q){
                    
            return true;
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
    binary_tree->traverse(TraversalType::IN_ORDER);
    TreeNode* q = binary_tree1->root;
    TreeNode* q1 = new TreeNode(2);
    TreeNode* q2 = new TreeNode(3);
    q->left = q1;
    q->right = q2;
    binary_tree1->traverse(TraversalType::IN_ORDER);
    bool is_same = solution.is_same_tree(p, q);
    return 0;
}
