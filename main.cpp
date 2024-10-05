#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <chrono>
#include <queue>
#include "includes/linkedlist.h"
#include "includes/binary_tree.h"

// ====================================================
// 104. Maximum Depth of Binary Tree 
// ====================================================
// Given the root of a binary tree, return its maximum depth.
//
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

int max_depth(TreeNode* root){
    if(root == nullptr) return 0;
    int level = 0;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int level_size = q.size();
        for(size_t i = 0; i < level_size; i++){
            TreeNode* temp_node = q.front();
            q.pop();
            if(temp_node->left != nullptr)
                q.push(temp_node->left);
            if(temp_node->right != nullptr)
                q.push(temp_node->right);
        }
        level++;
    }
    return level;
}

void problem_maximum_depth_binary(){
    BinaryTree* binary_tree = new BinaryTree(3);
    TreeNode* node = new TreeNode(9);
    TreeNode* node1 = new TreeNode(20);
    binary_tree->root->left = node;
    binary_tree->root->right = node1;
    TreeNode* node2 = new TreeNode(15);
    TreeNode* node3 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    int level = max_depth(binary_tree->root);
    std::cout << "level: " << level << std::endl;
}

int main(){
    BinaryTree* binary_tree = new BinaryTree(10);
    binary_tree->insert(5);
    binary_tree->insert(15);
    binary_tree->insert(3);
    binary_tree->insert(7);
    binary_tree->insert(12);
    binary_tree->insert(18);

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
