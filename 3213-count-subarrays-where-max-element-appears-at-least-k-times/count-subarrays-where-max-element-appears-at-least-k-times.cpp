class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
           int maxi = *max_element(nums.begin(),nums.end());
           int i= 0,j=0;
           long long ans=0;
           long long count=0;
           while(j<nums.size()){
                   if(nums[j]==maxi)count++;

                   if(count==k){
                    while(count==k){
                        ans+=nums.size()-j;
                        if(nums[i]==maxi)count--;
                        i++;
                    }
                   }
                   j++;
           }
           return ans;
    }
};