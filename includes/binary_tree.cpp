#include <algorithm>
#include <iostream>
#include <queue>
#include <stdexcept>
#include "binary_tree.h"
#include <stack>

BinaryTree::BinaryTree(int value){
    root = new TreeNode(value);
    size++;
}

TreeNode* BinaryTree::insert(int value){
    TreeNode* tree_node = new TreeNode(value);
    if(root == nullptr){
        root = tree_node; 
        size++;
        return root;
    }
    else{
        TreeNode* temp_node = root; 
        while(temp_node != nullptr){
            if(value < temp_node->value){
                if(temp_node->left == nullptr){
                    temp_node->left = tree_node;
                    size++;
                    return tree_node;
                }
                temp_node = temp_node->left;
            }else if(value > temp_node->value){
                if(temp_node->right == nullptr){
                    temp_node->right = tree_node;
                    size++;
                    return tree_node;
                }
                temp_node = temp_node->right;
            }else{
                return nullptr;
            }
        }

    }
    return nullptr;
}

TreeNode* BinaryTree::find(int value){
    if(root == nullptr)
        return nullptr;
    TreeNode* temp_node = root;
    while(temp_node != nullptr){
        if(value == temp_node->value){
            return temp_node;
        }else{
            if(value < temp_node->value)
                temp_node = temp_node->left;
            else if(value > temp_node->value)
                temp_node = temp_node->right;
            else
                temp_node = nullptr;;
        }
    }
    return nullptr;
}

void BinaryTree::traverse(TraversalType type){
    switch(type){
        case TraversalType::LEVEL_ORDER:
            level_order_traversal();
            break;
        case TraversalType::PRE_ORDER:
            pre_order_traversal();
            break;
        case TraversalType::IN_ORDER:
            in_order_traversal();
            break;
        case TraversalType::POST_ORDER:
            throw std::invalid_argument("POST_ORDER traversal function is missing!");
            break;
    }
}

void BinaryTree::level_order_traversal(){
    if(root == nullptr) return;
    std::queue<TreeNode*> que;
    que.push(root);
    int level = 0;
    while(!que.empty()){
        for(size_t i = 0; i < que.size(); i++){
            TreeNode* temp_node = que.front();
            std::cout << "Node data: " << temp_node->value << std::endl;
            que.pop();
            if(temp_node->left != nullptr)
                que.push(temp_node->left);
            if(temp_node->right != nullptr)
                que.push(temp_node->right);
        }
        level++;
    }
    std::cout << "Tree max depth: " << level << std::endl;
}

void BinaryTree::pre_order_traversal(){
    if(root == nullptr) return;
    std::stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* temp = s.top();
        s.pop();
        std::cout << "Node data: " << temp->value << std::endl;
        if(temp->right != nullptr){
            s.push(temp->right);
        }
        if(temp->left != nullptr){
            s.push(temp->left);
        }
    }
}

void BinaryTree::in_order_traversal(){
    if(root == nullptr) return;
    std::stack<TreeNode*> s;
    TreeNode* temp_node = root;
    while(temp_node != nullptr || !s.empty()){
        while(temp_node != nullptr){
            s.push(temp_node);
            temp_node = temp_node->left;
        }
        temp_node = s.top();
        s.pop();
        std::cout << "Node data: " << temp_node->value << std::endl;
        temp_node = temp_node->right;
    }
}

void BinaryTree::traverse_recursive(TraversalTypeRecursive type){
    switch(type){
        case TraversalTypeRecursive::RECURSIVE_PRE_ORDER:
            pre_order_traversal_recursive(root);
            break;
        case TraversalTypeRecursive::RECURSIVE_IN_ORDER:
            in_order_traversal_recursive(root);
            break;
        case TraversalTypeRecursive::RECURSIVE_POST_ORDER:
            post_order_traversal_recursive(root);
            break;
    }
}

void BinaryTree::pre_order_traversal_recursive(TreeNode* root){
    if(root == nullptr) return;
    std::cout << "node value: " << root->value << std::endl;
    pre_order_traversal_recursive(root->left);
    pre_order_traversal_recursive(root->right);
}

void BinaryTree::in_order_traversal_recursive(TreeNode* root){
    if(root == nullptr) return;
    in_order_traversal_recursive(root->left);
    std::cout << "node value: " << root->value << std::endl;
    in_order_traversal_recursive(root->right);
}

void BinaryTree::post_order_traversal_recursive(TreeNode* root){
    if(root == nullptr) return;
    post_order_traversal_recursive(root->left);
    post_order_traversal_recursive(root->right);
    std::cout << "node value: " << root->value << std::endl;
}

int BinaryTree::max_depth(){
    return max_depth(root);
}

int BinaryTree::max_depth(TreeNode* node){
    if(node == nullptr) return 0;
    int l = max_depth(node->left);
    int r = max_depth(node->right);
    return std::max(l, r) + 1;
}
