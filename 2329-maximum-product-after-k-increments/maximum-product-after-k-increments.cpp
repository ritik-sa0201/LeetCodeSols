class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = 1e9+7;
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int i=0;i<nums.size();i++){
            minh.push(nums[i]);
        }
        while(k--){
            int top = minh.top();minh.pop();minh.push(top+1);
        }
        long long ans = 1;
        while(!minh.empty()){
            ans = (ans*minh.top())%mod;
            minh.pop();
        }
        return int(ans);
    }
};