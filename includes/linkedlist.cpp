#include <iostream>
#include "linkedlist.h"
    
LinkedList::LinkedList(int value){
    head = new ListNode(value);
    tail = head;
}

LinkedList::~LinkedList(){
    ListNode* current = head;
    while(current != nullptr){
        ListNode* next_node = current->next;
        delete current;
        current = next_node;
    }
}

ListNode* LinkedList::add_last(int value){
    ListNode* node = new ListNode(value);
    if(tail != nullptr){
        tail->next = node;
    }else{
        head = node;
    }
    tail = node;
    return node;
}

void LinkedList::traverse_list(){
    ListNode* temp = head;
    while(temp != nullptr){
        std::cout << "address: " << temp << " , value: " << temp->val << " , points to: " << temp->next << std::endl;
        temp= temp->next;
    }
}
