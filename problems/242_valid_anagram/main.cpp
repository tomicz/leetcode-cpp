#include <iostream>
#include <string>

class Solution{
    public:
        bool isAnagram(std::string s, std::string t){
            
            return false;
        }
};


int main(){
    std::string s = "anagram";
    std::string t = "nagaram";
    Solution solution;
    bool is_anagram = solution.isAnagram(s, t);
    std::cout << "is anagram: " << is_anagram << std::endl;
    std::string s1 = "rat";
    std::string s2 = "car";
    bool is_anagram1 = solution.isAnagram(s1, s2);
    return 0;
}
