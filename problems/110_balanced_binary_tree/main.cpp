#include <iostream>

class Solution{
    public:
        bool is_balanced(){

            return false;
        }
};

int main(){
    Solution solution;
    bool balanced = solution.is_balanced();

    std::cout << std::boolalpha;
    std::cout << "is balanced: " << balanced << std::endl;

    return 0;
}
