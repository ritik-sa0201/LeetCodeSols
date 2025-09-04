class Solution {
    int maxn,mini;
    int mod = 1e9+7;
    vector<vector<vector<int>>>dp;
 
    vector<int> gp;
     int solve(int i,int sum,int curr,vector<int>&profit){
        if(i==profit.size()){
           if(curr>=mini) return 1;
           return 0;
        }
        if(dp[i][sum][curr]!=-1)return dp[i][sum][curr];
        int count = 0;
        curr+=profit[i];
        sum=sum+gp[i];
        if(sum<=maxn){
         count+=solve(i+1,sum,curr,profit);
        }
         curr-=profit[i];
         sum=sum-gp[i];
         count+=solve(i+1,sum,curr,profit);
         return  dp[i][sum][curr] = count%mod;
         }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        maxn=n,mini=minProfit;
          dp.assign(profit.size() + 1,
                  vector<vector<int>>(n + 1, vector<int>(8000, -1)));
        gp=group;
        vector<int>op;
        return solve(0,0,0,profit);
    }
};