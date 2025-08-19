class Solution {
    void solve(int i,vector<int>&nums,vector<int>curr,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(i+1,nums,curr,ans);
        curr.pop_back();
        solve(i+1,nums,curr,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,nums,curr,ans);
        return ans;
    }
};