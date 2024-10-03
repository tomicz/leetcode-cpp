#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

class Solution{
    public:
        bool isPalindrome(std::string s){
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            std::string s_formatted;
            for(char c: s){
                if(c > 47 && c < 58)
                    s_formatted += c;
                if(c > 96 && c < 123)
                    s_formatted += c;
            }
            int l = 0;
            int r = s_formatted.size() - 1;
            while(l < r){
                if(s_formatted[l] != s_formatted[r])
                    return false;
                l++;
                r--;
            }
            return true; 
        }
};

int main(){
    Solution solution;
    std::string s = "A man, a plan, a canal: Panama";
    bool is_palindrome = solution.isPalindrome(s);
    std::cout << std::boolalpha;
    std::cout << "is palindrome: " << is_palindrome << std::endl;
    return 0;
}
