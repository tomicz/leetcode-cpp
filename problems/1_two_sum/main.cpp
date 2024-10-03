#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target){
            std::unordered_map<int, int> map;
            for(size_t i = 0; i < nums.size(); i++){
                int compliment = target - nums[i];
                if(map.find(compliment) != map.end()){
                    return {map[compliment], static_cast<int>(i)};
                }
                map[nums[i]] = i;
            }
            return {}; 
        }
};

int main(){
    Solution solution;
    std::vector<int> input = {2,7,11,15};
    int target = 9;
    std::vector<int> indicies = solution.twoSum(input, target);
    for(size_t i = 0; i < indicies.size(); i++){
        std::cout << "index: " << indicies[i] << std::endl;
    }
    return 0;
}
