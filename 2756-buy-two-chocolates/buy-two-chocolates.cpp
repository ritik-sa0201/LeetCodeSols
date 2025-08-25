class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int sum=0;
        sum+=prices[0];
        sum+=prices[1];
        if(sum>money)return money;
        else return money-sum;
    }
};