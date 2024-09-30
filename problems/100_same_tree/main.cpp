#include <iostream>
#include <stack>
#include "../../includes/binary_tree.h"

class Solution{
    public:
        bool is_same_tree(TreeNode* p, TreeNode* q){
            std::stack<TreeNode*> a_stack;
            std::stack<TreeNode*> b_stack;
            a_stack.push(p);
            b_stack.push(q);
            while(a_stack.size() > 0 && b_stack.size() > 0){
                TreeNode* a = a_stack.top();     
                TreeNode* b = b_stack.top();     
                a_stack.pop(); 
                b_stack.pop();
                if(a == nullptr && b == nullptr) continue;
                if(a == nullptr || b == nullptr || a->value != b->value) return false;
                a_stack.push(a->left);
                a_stack.push(a->right);

                b_stack.push(b->left);
                b_stack.push(b->right);
            }

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
