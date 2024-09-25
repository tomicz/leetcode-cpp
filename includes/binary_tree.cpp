#include <iostream>
#include "binary_tree.h"

BinaryTree::BinaryTree(int value){
    root = new TreeNode(value);
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
                    std::cout << "node added: " << tree_node->value << std::endl;
                    return tree_node;
                }
                temp_node = temp_node->left;
            }else if(value > temp_node->value){
                if(temp_node->right == nullptr){
                    temp_node->right = tree_node;
                    size++;
                    std::cout << "node added: " << tree_node->value << std::endl;
                    return tree_node;
                }
                temp_node = temp_node->right;
            }else{
                std::cout << "node already exists" << std::endl;
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
