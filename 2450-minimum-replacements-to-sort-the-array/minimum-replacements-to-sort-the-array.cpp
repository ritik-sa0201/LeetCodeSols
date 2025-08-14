class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        long long ans=0;
        for(int i=n-2;i>=0;i--){
          if(nums[i]>nums[i+1]){
            long long steps = (nums[i]-1)/nums[i+1];
            nums[i]=nums[i]/(steps+1);
            ans+=steps;
          }
        }
        return ans;
    }
};