#include <iostream>
#include <string>

class Solution{
    public:
        bool isAnagram(std::string s, std::string t){
            if(s.size() != t.size()) return false;
            std::array<int, 26> arr = {0};
            for(size_t i = 0; i < s.size(); i++){
                arr[s[i] - 'a']++;
                arr[t[i] - 'a']--;
            }
            for(size_t i = 0; i < arr.size(); i++){
                if(arr[i] != 0) return false;
            }
            return true;
        }
};


int main(){
    std::string s = "anagram";
    std::string t = "nagaram";
    Solution solution;
    bool is_anagram = solution.isAnagram(s, t);
    std::cout << std::boolalpha;
    std::cout << "is anagram: " << is_anagram << std::endl;
    std::string s1 = "rat";
    std::string s2 = "car";
    bool is_anagram1 = solution.isAnagram(s1, s2);
    std::cout << "is anagram1: " << is_anagram1 << std::endl;
    return 0;
}
