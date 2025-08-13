class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if(nums.size()==1)return 0;

        sort(nums.begin(),nums.end());
       int ans =0;
       for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){
            ans += 1;
            nums[i]=nums[i]+1;
        }
        else if(nums[i]<nums[i-1]){
         ans =ans+(nums[i-1]+1)-nums[i];
         nums[i]=nums[i-1]+1;
        }
       }
       return ans;
    }
};