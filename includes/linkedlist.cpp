#include <iostream>
#include "linkedlist.h"

void traverse_list(ListNode* head){
    while(head != nullptr){
        std::cout << "address: " << head << " , value: " << head->val << " , points to: " << head->next << std::endl;
        head = head->next;
    }
}
