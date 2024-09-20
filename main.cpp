#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

void traverse_list(ListNode* head);

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
    ListNode* list1NodeC = new ListNode(4, nullptr);    
    ListNode* list1NodeB = new ListNode(2, list1NodeC);    
    ListNode* list1NodeA = new ListNode(1, list1NodeB);    
    traverse_list(list1NodeA);

    std::cout << "=======" << std::endl;
    std::cout << "list2" << std::endl;
    std::cout << "=======" << std::endl;
    ListNode* list2NodeD = new ListNode(5, nullptr);    
    ListNode* list2NodeC = new ListNode(4, list2NodeD);    
    ListNode* list2NodeB = new ListNode(3, list2NodeC);    
    ListNode* list2NodeA = new ListNode(1, list2NodeB);    
    traverse_list(list2NodeA);

    std::cout << "=======" << std::endl;
    std::cout << "merged_list" << std::endl;
    std::cout << "=======" << std::endl;
    ListNode* head = merge_two_lists(list1NodeA, list2NodeA);
    traverse_list(head);
}

// ====================================================
// 206. Reverse Linked List 
// ====================================================

ListNode* create_linked_list(){
    ListNode* node5 = new ListNode(5, nullptr);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2= new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);
    return head;
}

ListNode* reverse_list(ListNode* head) {
    ListNode* prev = nullptr;
    while(head != nullptr){
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
        std::cout << "address: " << prev << " , value: " << prev->val << " , points to: " << prev->next << std::endl;
    }
    return prev;
}

void traverse_list(ListNode* head){
    while(head != nullptr){
        std::cout << "address: " << head << " , value: " << head->val << " , points to: " << head->next << std::endl;
        head = head->next;
    }
}

void problem_reverse_linked_list(){
    ListNode* head = create_linked_list();
    reverse_list(head);
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
    problem_merge_two_sorted_lists();
    return 0;


}
