#include <iostream>
#include <vector>

class Solution {
    void sort(std::vector<int>& nums){
        for(size_t i = 1; i < nums.size(); i++){
            size_t j = i - 1;
            int temp = nums[i];
            while(j>=0 && nums[j] > temp){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = temp;
        }
    }
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int> nums) {
            std::vector<std::vector<int>> triplets;
            
            return triplets;
        }
};

int main(){
    Solution solution;
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> result = solution.threeSum(nums);
    return 0;
}
