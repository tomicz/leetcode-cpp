#include <iostream>
#include <stack>

class Solution{
    public:
        bool isValid(std::string s){
            return false;
        }
};

int main(){
    Solution solution;
    std::string s = "()[]{}";
    bool is_valid = solution.isValid(s);
    std::cout << std::boolalpha;
    std::cout << "is valid: " << is_valid << std::endl;
    return 0;
}
