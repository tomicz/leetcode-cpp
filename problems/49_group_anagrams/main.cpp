#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>

class Solution{
    public:
        void sort(std::string& str){
            for(size_t i = 0; i < str.size(); i++){
                for(size_t j = 0; j < str.size()-1; j++){
                    if(str[j] > str[j+1]){
                        char temp = str[j];
                        str[j] = str[j+1];
                        str[j+1] = temp;
                    }
                }
            }
        }

        std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
            std::unordered_map<std::string, std::vector<std::string>> m;
            for(std::string& str: strs){
                std::string key = str;
                sort(key);
                m[key].push_back(str);
            }

            std::vector<std::vector<std::string>> anagrams;
            for(auto i: m){
                anagrams.push_back(i.second);
            }

            return anagrams;
        }
};

int main(){
    Solution solution; 
    std::vector<std::string> anagram_groups = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> anagrams = solution.groupAnagrams(anagram_groups);
    return 0;
}
