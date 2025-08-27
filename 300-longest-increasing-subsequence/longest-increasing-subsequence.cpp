class Solution {
public:
  vector<vector<int>>dp;
   int solve(int i,int n,int prev,vector<int>&nums){
    if(i==n)return 0;
    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    int notPick = solve(i+1,n,prev,nums);
    int pick = 0;
    if(prev==-1|| nums[i]>nums[prev]){
        pick = 1+solve(i+1,n,i,nums);
    }
    return dp[i][prev+1] =  max(pick,notPick);
   }


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        if(nums.size()==1)return 1;
        return solve(0,n,-1,nums);
    }
};