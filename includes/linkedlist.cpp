#include <iostream>
#include "linkedlist.h"
    
LinkedList::LinkedList(int value){
    head = new ListNode(value);
    tail = head;
}

void LinkedList::add_last(int value){
    ListNode* node = new ListNode(value);
    if(tail != nullptr){
        tail->next = node;
    }else{
        head = node;
    }
    tail = node;
}

void LinkedList::traverse_list(){
    ListNode* temp = head;
    while(temp != nullptr){
        std::cout << "address: " << temp << " , value: " << temp->val << " , points to: " << temp->next << std::endl;
        temp= temp->next;
    }
}
