class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        int count=0;
        unordered_map<int,int>curr;

        int i=0,j=0;
        int n=nums.size();
        while(j<n){
            curr[nums[j]]++;
            if(mp.size()==curr.size()){
                while(mp.size()==curr.size()){
                count += n-j;
                curr[nums[i]]--;
                if(curr[nums[i]]==0)curr.erase(nums[i]);
                i++;
                }
            }
            j++;
        }
        return count;
    }
};