class Solution {
    int l,h,z,o;
    int mod=1e9+7;
   vector<int>dp;
    int solve(int len){
        if(len>h)return 0;        
        int ans = 0;
        if(dp[len]!=-1)return dp[len];
        if(l<=len && len<=h)ans += 1;
        ans += solve(len+z);
        ans +=solve(len+o);
        return dp[len]= ans%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
          l=low,h=high,z=zero,o=one;
          dp.resize(high+1,-1);
          return solve(0);
    }
};