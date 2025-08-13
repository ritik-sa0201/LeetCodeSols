class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        vector<pair<int,int>> x;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(abs(nums[i]-nums[j])<=min(nums[i],nums[j])){
                    x.push_back({nums[i],nums[j]});
                }
            }
        }
        int ans=0;
        for(int i=0; i<x.size(); i++){
           int curr= x[i].first ^ x[i].second;
           ans=max(curr,ans);
        }
        return ans;
    }
};