class Solution {
    int count=0;

   void solve(int i,vector<int>&nums,int k,vector<int>&op){
    if(i==nums.size()){
       for(int x=0;x<op.size();x++){
        for(int j=x+1;j<op.size();j++){
            if(abs(op[x]-op[j])==k)return;
        }
       }
        count++;
         return;
    }
       op.push_back(nums[i]);
       solve(i+1,nums,k,op);
       op.pop_back();
       solve(i+1,nums,k,op);
   }



public:
    int beautifulSubsets(vector<int>& nums, int k) {
         vector<int>op;
         solve(0,nums,k,op);
         return count-1;
    }
};