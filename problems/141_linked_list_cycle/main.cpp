#include <iostream>
#include "../../includes/linkedlist.h"

class Solution{
    public:
        bool hasCycle(ListNode* head){
            ListNode* slow_pointer = head;
            ListNode* fast_pointer = head;
            while(fast_pointer != nullptr && fast_pointer->next != nullptr){
                if(slow_pointer == fast_pointer)
                    return true;
                slow_pointer = slow_pointer->next;
                fast_pointer = fast_pointer->next->next;
            }
            return false;
        }
};

int main(){
    Solution solution;
    LinkedList* linked_list = new LinkedList(3);
    linked_list->add_last(2);
    linked_list->add_last(0);
    linked_list->add_last(-4);
    ListNode* node = linked_list->find(-4);
    node->next = linked_list->find(2);
    std::cout << node->val << std::endl;
    std::cout << node->next->val << std::endl;
    bool has_cycle = solution.hasCycle(linked_list->head);
    std::cout << std::boolalpha;
    std::cout << "has cycle: " << has_cycle << std::endl;
    return 0;
}
