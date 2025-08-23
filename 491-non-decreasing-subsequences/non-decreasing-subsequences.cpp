class Solution {
 vector<vector<int>>ans;
 
  void solve(int i,vector<int>&nums,int prev,vector<int>&curr){
    if(i==nums.size()){
        if(curr.size()>=2){
            for(int x=0;x<ans.size();x++){
                if(ans[x]==curr)return;
            }
            ans.push_back(curr);
        }
        return;
    }
    //pick
        if(nums[i]>=prev || prev==-101){
            curr.push_back(nums[i]);
            solve(i+1,nums,nums[i],curr);
            curr.pop_back();
        }
     //not pick
           solve(i+1,nums,prev,curr);   
  }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>curr;
        solve(0,nums,-101,curr);
        return ans;
    }
};