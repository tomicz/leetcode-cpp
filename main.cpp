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


// ====================================================
// 141. Linked List Cycle 
// ====================================================
//
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
//
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
//
// Return true if there is a cycle in the linked list. Otherwise, return false.

bool hasCycle(ListNode *head) {
    ListNode* slow_pointer = head;
    ListNode* fast_pointer = head;
    while(fast_pointer != nullptr && fast_pointer->next != nullptr){
       slow_pointer = slow_pointer->next; 
       fast_pointer = fast_pointer->next->next; 
       if(slow_pointer == fast_pointer)
           return true;
    }
    return false;        
}

void problem_linked_list_cycle(){
    LinkedList* linked_list = new LinkedList(3);
    ListNode* link = linked_list->add_last(2);
    linked_list->add_last(0);
    linked_list->add_last(-4)->next = link;
    bool isCycle = hasCycle(linked_list->head);
    std::cout << "has cycle: " << isCycle << std::endl;
}

// ====================================================
// 21. Merge Two Sorted Lists
// ====================================================


ListNode* merge_two_lists(ListNode* list1, ListNode* list2){
    ListNode temp_node; 
    ListNode* current_node = &temp_node;

    while(list1 != nullptr && list2 != nullptr){
        if(list1->val < list2->val){
           current_node->next = list1; 
           list1 = list1->next;
        }
        else{
            current_node->next = list2;
            list2 = list2->next;
        }

        current_node = current_node->next;
    }

    if(list1 != nullptr)
        current_node->next = list1;
    if(list2 != nullptr)
        current_node->next = list2;

    return temp_node.next;
}

void problem_merge_two_sorted_lists(){
    std::cout << "=======" << std::endl;
    std::cout << "list1" << std::endl;
    std::cout << "=======" << std::endl;
    LinkedList* linked_list1 = new LinkedList(1);
    linked_list1->add_last(2);
    linked_list1->add_last(4);
    linked_list1->traverse_list();

    std::cout << "=======" << std::endl;
    std::cout << "list2" << std::endl;
    std::cout << "=======" << std::endl;
    LinkedList* linked_list2 = new LinkedList(1);
    linked_list2->add_last(3);
    linked_list2->add_last(4);
    linked_list2->add_last(5);
    linked_list2->traverse_list();

    std::cout << "=======" << std::endl;
    std::cout << "merged_list" << std::endl;
    std::cout << "=======" << std::endl;

    LinkedList* linked_list3 = new LinkedList(0);
    linked_list3->head = merge_two_lists(linked_list1->head, linked_list2->head);
    linked_list3->traverse_list();
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
