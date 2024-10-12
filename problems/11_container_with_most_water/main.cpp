#include <iostream>
#include <vector>

class Solution{
    public:
        int maxArea(std::vector<int>& heights){
            int max_area = 0;
            int l = 0;
            int r = heights.size()-1;
            while(l < r){
                int area = (r - l) * std::min(heights[l], heights[r]);
                max_area = std::max(max_area, area);
                if(heights[l] < heights[r])
                    l++;
                else
                    r--;
            }
            return max_area;
        }
};

int main(){
    Solution solution;
    std::vector<int> heights = {1,8,6,2,5,4,8,3,7};
    int max_area = solution.maxArea(heights);
    std::cout << "Max area: " << max_area << std::endl;
    return 0;
}
