#include <iostream>
#include <vector>

class Solution {
    void sort(std::vector<int>& nums){
        for(size_t i = 1; i < nums.size(); i++){
            int j = i - 1;
            int temp = nums[i];
            while(j>=0 && nums[j] > temp){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = temp;
        }
    }
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            std::vector<std::vector<int>> v;
            if(nums.size() < 3) return {};
            sort(nums);
            for(size_t i = 0; i < nums.size(); i++){
                if(i > 0 && nums[i] == nums[i - 1]) continue;
                int l = i + 1;
                int r = nums.size() -1;
                while(l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum > 0){
                        r--;
                    }
                    else if(sum < 0){
                        l++;
                    }else{
                        v.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        while(nums[l] == nums[l-1] && l < r){
                            l++;
                        }
                    }
                }
            }
            return v;
        }
};

int main(){
    Solution solution;
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> result = solution.threeSum(nums);
    return 0;
}
