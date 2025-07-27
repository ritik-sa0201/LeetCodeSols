class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0,j=0;
        int maxm = INT_MIN;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[nums[j]] <= k){
               maxm = max(maxm,j-i+1);
            }
            else if(mp[nums[j]] > k){
                while(mp[nums[j]] > k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        return maxm;
    }
};