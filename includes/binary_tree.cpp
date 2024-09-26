#include <iostream>
#include <queue>
#include <stdexcept>
#include "binary_tree.h"

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
            throw std::invalid_argument("PRE_ORDER traversal function is missing!");
            break;
        case TraversalType::IN_ORDER:
            throw std::invalid_argument("IN_ORDER traversal function is missing!");
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
    while(!que.empty()){
        TreeNode* temp_node = que.front();
        std::cout << "Node data: " << temp_node->value << std::endl;
        que.pop();
        if(temp_node->left != nullptr)
            que.push(temp_node->left);
        if(temp_node->right != nullptr)
            que.push(temp_node->right);
    }
}
