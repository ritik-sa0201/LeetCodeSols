class Solution {
    void solve(int i,int x,int sum,vector<int>&op,vector<vector<int>>&ans,vector<int>&arr,int k,int n){
      
      if(i==arr.size()){
      if(x==k && sum==n){
        ans.push_back(op);
      }
      return;
      }

      op.push_back(arr[i]);
      solve(i+1,x+1,sum+arr[i],op,ans,arr,k,n);
      op.pop_back();
  solve(i+1,x,sum,op,ans,arr,k,n);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<int>arr(9,0);
       for(int i=0;i<9;i++){
        arr[i] = i+1;
       } 
       vector<vector<int>>ans;
       vector<int>op;
       solve(0,0,0,op,ans,arr,k,n);
       return ans;
    }
};