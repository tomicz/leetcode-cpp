#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <chrono>
#include "includes/linkedlist.h"

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

// ====================================================
// 206. Reverse Linked List 
// ====================================================

ListNode* reverse_list(ListNode* head) {
    ListNode* prev = nullptr;
    while(head != nullptr){
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}


void problem_reverse_linked_list(){
    LinkedList* linked_list = new LinkedList(1);
    linked_list->add_last(2);
    linked_list->add_last(3);
    linked_list->add_last(4);
    linked_list->add_last(5);
    linked_list->add_last(6);
    linked_list->traverse_list();
    linked_list->head = reverse_list(linked_list->head);
    linked_list->traverse_list();
}    


// ====================================================
// 121. Best Time to Buy and Sell Stock
// ====================================================
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
//
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// 
// Example 2:
// 
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

int max_profit(std::vector<int>& prices){
    int pointerA = prices[0];
    int pointerB = 0;
    for(int i = 0; i < prices.size(); i++){
        if(pointerA > prices[i]){
            pointerA = prices[i];
        }
        pointerB = std::max(pointerB, prices[i] - pointerA);
    }
    return pointerB;
}

void problem_buy_stock(){
    std::vector<int> inputA = {7, 1, 5, 3, 6, 4};
    std::vector<int> inputB = {7, 6, 4, 3, 1};

    int resultA = max_profit(inputA);
    int resultB = max_profit(inputB);

    std::cout << "result a: " << resultA << std::endl;
    std::cout << "result b: " << resultB << std::endl;
}

// ====================================================
// BINARY SEARCH
// ====================================================

int search(std::vector<int> nums, int target){
    int l = 0;
    int r = nums.size() -1;
    int m = l;

    while(l <= r){
        m = l + (r - l) / 2;
        if(nums[m] < target)
            l = m + 1;
        else if(nums[m] > target)
            r = m - 1;
        else
            return m; 
    }

    return -1;
}
void problem_binary_search(){
    std::vector<int> inputA = {-1, 0, 3, 5, 9, 12};
    int targetA = 9;
   
   int result = search(inputA, targetA); 
   std::cout << "binary search result: " << result << std::endl;
}

bool isValid(std::string s){
    std::stack<char> newStack;
    bool isValid = false;
    if(s.size() % 2 != 0) return false;
    for(size_t i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            newStack.push(s[i]);
        else if(!newStack.empty() && s[i] == ')' && newStack.top() == '(')
            newStack.pop();
        else if(!newStack.empty() && newStack.top() == '[' && s[i] == ']')
            newStack.pop();
        else if(!newStack.empty() && newStack.top() == '{' && s[i] == '}')
            newStack.pop();
    } 
    isValid = newStack.size() == 0 ? true : false;
    std::cout << "is valid: " << isValid << std::endl;
    std::cout << std::endl;
    return isValid;
}

bool isPalindrome(std::string s){
    if(s.empty()) return false;
    if(s.size() == 1) return true;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::string filtered_string;
    for(char c: s){
        if(c > 47 && c < 58 || c > 96 && c < 123)
            filtered_string += c; 
    }
    int r = 0;
    int l = filtered_string.size() -1;
    while(r < l){
        if(filtered_string[r] != filtered_string[l])
            return false;
        r++;
        l--;
    }
    return true;
}

std::vector<int> two_sum(std::vector<int>& nums, int target){
    std::unordered_map<int, int> umap;
    std::vector<int> indicies; 
    for(size_t i = 0; i < nums.size(); i++){
        int sum = target - nums[i];
        if(umap.find(sum) != umap.end()){
            indicies.push_back(i);
            indicies.push_back(umap[sum]);
        }else{
            umap[nums[i]] = i;
        }
    } 
    return indicies;
}

// ====================================================
// 217. Contains Duplicate
// ====================================================

bool contains_duplicate(std::vector<int>& nums){
    for(size_t i = 0; i < nums.size(); i++){
        for(size_t j = i + 1; j < nums.size(); j++){
           if(nums[i] == nums[j]){
               return true;
           }
        }
    }

    return false;
}

void problem_contains_duplicate(){
    std::vector<int> vec = {1, 2, 3, 1};
    bool contains = contains_duplicate(vec);
    std::cout << "contains: " << contains << std::endl;
}

int main(){
    // TWO SUM
//    std::cout << "TWO SUM" << std::endl;
//    std::vector<int> nums = {2, 7, 11, 15};
//    int target = 9;
//    std::vector<int> result = two_sum(nums, target);
//    std::cout << result[0] << ", " << result[1] << std::endl;
//    std::cout << "IS PALINDROME" << std::endl;
//    std::string s = "A man, a plan, a canal: Panama";
//    std::string s1 = "race a car";
//    bool isp = isPalindrome(s); 
//    bool isp1 = isPalindrome(s1); 
//    std::cout << "is palindrome: " << isp << std::endl;
//    std::cout << "is palindrome: " << isp1 << std::endl;
//
//    std::cout << "Validate Parentheses" << std::endl;
//   
//    std::string a = "[]"; 
//    std::string a1 = "([{}])"; 
//    std::string a2 = "[(])"; 
//
//    isValid(a);
//    isValid(a1);
//    isValid(a2);
//
//    problem_binary_search();
    
//    problem_buy_stock();
//    problem_reverse_linked_list();
//    problem_merge_two_sorted_lists();
//    problem_linked_list_cycle();
    auto start = std::chrono::high_resolution_clock::now();
    problem_contains_duplicate();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

    return 0;


}
