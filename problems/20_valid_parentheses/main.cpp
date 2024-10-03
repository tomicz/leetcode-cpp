#include <iostream>
#include <stack>

class Solution{
    public:
        bool isValid(std::string s){
            std::stack<char> s_stack;
            if(s.size() % 2 != 0) return false;
            for(char c: s){
                if(c == '(' || c == '[' || c == '{')
                    s_stack.push(c);
                else if(!s_stack.empty() && s_stack.top() == '(' && c == ')')
                    s_stack.pop();
                else if(!s_stack.empty() && s_stack.top() == '[' && c == ']')
                    s_stack.pop();
                else if(!s_stack.empty() && s_stack.top() == '{' && c == '}')
                    s_stack.pop();
                else
                    return false;
            }
            if(s_stack.size() == 0) return true;
            return false;
        }
};

int main(){
    Solution solution;
    std::string s = "()[]{}";
    bool is_valid = solution.isValid(s);
    std::cout << std::boolalpha;
    std::cout << "is valid: " << is_valid << std::endl;
    std::string s1 = "(]";
    bool is_valid1 = solution.isValid(s1);
    std::cout << std::boolalpha;
    std::cout << "is valid1: " << is_valid1 << std::endl;
    return 0;
}
