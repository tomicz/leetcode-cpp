#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

void traverse_list(ListNode* head);

#endif // LINKEDLIST_H
