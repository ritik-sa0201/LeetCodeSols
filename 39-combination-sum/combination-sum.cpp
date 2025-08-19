class Solution {
    void solve(int i, vector<int>& nums,vector<int>curr,vector<vector<int>>&ans,int target){
      if(i==nums.size()){
        if(target==0){
            ans.push_back(curr);
        }
        return;
      }
      if(nums[i]<=target){
        curr.push_back(nums[i]);
        solve(i,nums,curr,ans,target-nums[i]);
        curr.pop_back();
        solve(i+1,nums,curr,ans,target);
      }
      else{
        solve(i+1,nums,curr,ans,target);
      }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,candidates,curr,ans,target);
        return ans;
    }
};