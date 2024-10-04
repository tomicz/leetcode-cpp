#include <iostream>
#include <vector>

class Solution{
    public:
        int search(std::vector<int>& nums, int target){
            int l = 0;
            int r = nums.size() -1;
            int m = l;
            while(l <= r){
                m = l + (r - l) / 2;
                if(nums[m] < target)
                    l = m + 1;
                else if(nums[m] > target)
                    r = m - 1; 
                else
                    return m;
            }
            return -1;
        }
};

int main(){
    Solution solution;    
    std::vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int result = solution.search(nums, target);
    std::cout << "result: " << result << std::endl;
    return 0;
}
