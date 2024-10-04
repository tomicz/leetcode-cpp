#include <iostream>
#include "../../includes/linkedlist.h"

class Solution{
    public:
        ListNode* reverseList(ListNode* head){
            ListNode* prev = nullptr; 
            while(head != nullptr){
                ListNode* temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
            }
            return prev;
        }
};

int main(){
    Solution solution;
    LinkedList* linkest_list = new LinkedList(1);
    ListNode* head = linkest_list->head;
    ListNode* prev = head;
    linkest_list->add_last(2);
    linkest_list->add_last(3);
    linkest_list->add_last(4);
    linkest_list->add_last(5);
    linkest_list->traverse_list();
    linkest_list->head = solution.reverseList(head);
    linkest_list->traverse_list();
    return 0;
}
