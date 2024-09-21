#include <iostream>
#include "linkedlist.h"
    
    LinkedList::LinkedList(ListNode* head) : head(head){};

    void LinkedList::traverse_list(){
        while(head != nullptr){
            std::cout << "address: " << head << " , value: " << head->val << " , points to: " << head->next << std::endl;
            head = head->next;
        }
    }
