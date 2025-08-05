class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0,i=0,j=0;
        int ans  =INT_MIN;
        int n = nums.size();
        unordered_map<int,int>mp;
        while(j<n){
            sum +=nums[j];
            mp[nums[j]]++;
            if(mp.size()== j-i+1){
                ans = max(ans,sum);
            }
           if(mp.size() < j-i+1){
            while(mp.size() < j-i+1){
                mp[nums[i]]--;
                sum -=nums[i];
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
           }
           j++;
        }
        return ans;
    }
};