class Solution {
    vector<int>dp;
    int solve(int n,vector<int>&nums){
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        //pick
        int ans=INT_MIN;
        ans=max(ans,nums[n]+solve(n-2,nums));
        //not pick
        ans = max(ans,solve(n-1,nums));
        return dp[n] = ans;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        return solve(n-1,nums);
    }
};