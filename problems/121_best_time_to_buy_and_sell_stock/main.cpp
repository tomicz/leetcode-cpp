#include <iostream>
#include <vector>

class Solution{
    public:
        int maxProfit(std::vector<int>& prices){
            int current_price = prices[0];
            int max_profit = 0;
            for(size_t i = 1; i < prices.size(); i++){
                if(current_price > prices[i])
                    current_price = prices[i];
                max_profit = std::max(max_profit, prices[i] - current_price);
            }
            return max_profit;  
        }
};

int main(){
    Solution solution;
    std::vector<int> vec = {7,1,5,3,6,4};
    int max_profit = solution.maxProfit(vec);
    std::cout << "max profit: " << max_profit << std::endl;
    return 0;
}
