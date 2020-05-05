class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int profit = 0;
        
        for(int i=1; i<prices.size(); i++){
            if(prices[i] < sell)
            {
                profit += sell - buy;
                buy = prices[i];
                sell = prices[i];
            }
            else {
                sell = prices[i];
            }
        }
        profit += sell - buy;
        return profit;
        
    }
};
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
// #Application