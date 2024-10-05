#include <iostream>
#include "../../includes/linkedlist.h"

class Solution{
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
            ListNode head; 
            ListNode* current_node = &head;
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
            else if(list2 != nullptr)
                current_node->next = list2;
            return head.next;
        }
};

int main(){
    Solution solution;
    std::cout << "Linked list 1" << std::endl;
    LinkedList* linked_list1 = new LinkedList(1);
    linked_list1->add_last(2);
    linked_list1->add_last(4);
    linked_list1->traverse_list();
    std::cout << "Linked list 2" << std::endl;
    LinkedList* linked_list2 = new LinkedList(1);
    linked_list2->add_last(3);
    linked_list2->add_last(4);
    linked_list2->traverse_list();
    std::cout << "Linked list 3" << std::endl;
    LinkedList* linked_list3 = new LinkedList(0);
    linked_list3->head = solution.mergeTwoLists(linked_list1->head, linked_list2->head);
    linked_list3->traverse_list(); 
    return 0;
}
