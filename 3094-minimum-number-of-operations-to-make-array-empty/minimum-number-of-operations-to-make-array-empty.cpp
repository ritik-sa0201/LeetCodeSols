class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int ans=0;
        for(auto&it : mp){
            int x = it.second;
            if(x<2)return -1;
             if(x%3==0){
                ans+=x/3;
             }
             else{
                ans += ceil((double)x / 3);
             }
        }
        return ans;
    }
};