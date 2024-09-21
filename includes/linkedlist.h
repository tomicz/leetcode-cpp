#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class LinkedList{
    public:
        ListNode* head;

        LinkedList(ListNode* head);

        void traverse_list();
};

#endif