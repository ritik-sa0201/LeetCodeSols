class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        for(int in:nums){
            mp[in]++;
            maxi = max(maxi,mp[in]);
        }
        //maxi me maxm degree h
        int ans  = INT_MAX; 
        for(auto& it:mp){
            if(it.second == maxi){
                int el = it.first;
                int i=0,j=nums.size()-1;
                while(i<=j){
                   if(nums[i]==el)break;i++;
                }
                while(j>=i){
                    if(nums[j]==el)break;j--;
                }
                ans = min(ans,j-i+1);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};