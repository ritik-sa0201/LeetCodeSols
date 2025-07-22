class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm = prices[0];
        int profit = INT_MIN;

        for(int i=0;i<prices.size();i++){
            if(prices[i] < minm){
                minm = prices[i];
            }
            profit = max(profit,prices[i]-minm);
        }
        return profit;
    }
};