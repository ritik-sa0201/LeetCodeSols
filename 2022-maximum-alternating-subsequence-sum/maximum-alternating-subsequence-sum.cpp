class Solution {

   long long solve(int i,bool even,vector<int>&nums,vector<vector<long long>> &dp){
    if(i>=nums.size()) return 0;
    if(dp[i][even]!=-1) return dp[i][even];
     long long ans = INT_MIN;
     if(even){
        ans=max(ans,nums[i]+solve(i+1,false,nums,dp));
        ans=max(ans,solve(i+1,true,nums,dp));
     }
     else{
        ans=max(ans,-nums[i]+solve(i+1,true,nums,dp));
        ans=max(ans,solve(i+1,false,nums,dp));
     }
     return dp[i][even]=ans;
   }

public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return solve(0,true,nums,dp);
    }
};