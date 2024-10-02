#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
    public:
        bool containsDuplicate(std::vector<int>& nums){
            std::unordered_map<int, int> map;
            for(size_t i = 0; i < nums.size(); i++){
                if(map.find(nums[i]) != map.end()){
                    return true;
                }
                map[nums[i]] = i;
            }
            return false;
        }
};


int main(){
    std::vector<int> input = {1,2,3,1};
    Solution solution;
    bool contains_duplicate = solution.containsDuplicate(input);
    std::cout << std::boolalpha;
    std::cout << "contains duplicate: " << contains_duplicate << std::endl;
    return 0;
}
