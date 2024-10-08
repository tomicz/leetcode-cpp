#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<int> twoSum(std::vector<int>& numbers, int target){
            int l = 0;
            int r = numbers.size()-1;
            while(l < r){
                int current_sum = numbers[l] + numbers[r];
                if(current_sum > target)
                    r--;
                else if(current_sum < target)
                    l++;
                else
                    return {l+1, r+1};
            }
            return {};
        }
};

int main(){
    Solution solution;   
    std::vector<int> numbers = {2,7,11,15};
    int target = 9;
    auto sum = solution.twoSum(numbers, target);
    for(int i: sum){
        std::cout << i << ", ";
    }
    return 0;
}
