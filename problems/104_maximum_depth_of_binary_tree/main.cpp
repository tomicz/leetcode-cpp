#include <iostream>
#include <queue>
#include "../../includes/binary_tree.h"

class Solution{
    public:
        int maxDepth(TreeNode* root){
            if(root == nullptr) return 0;
            std::queue<TreeNode*> q;
            int level = 0;
            q.push(root);
            while(!q.empty()){
                int level_size = q.size();
                for(size_t i = 0; i < level_size; i++){
                    TreeNode* curr_node = q.front();
                    q.pop();
                    if(curr_node->left != nullptr)
                        q.push(curr_node->left);
                    if(curr_node->right != nullptr)
                        q.push(curr_node->right);
                }
                level++;
            }
            return level;
        }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(3);
    TreeNode* nodeA = new TreeNode(9);
    TreeNode* nodeB = new TreeNode(20);
    TreeNode* nodeC = new TreeNode(15);
    TreeNode* nodeD = new TreeNode(7);
    root->left = nodeA;
    root->right = nodeB;
    root->right->left = nodeC;
    root->right->right = nodeD;
    int max_depth = solution.maxDepth(root);
    std::cout << "max depth: " << max_depth << std::endl;
    return 0;
}
