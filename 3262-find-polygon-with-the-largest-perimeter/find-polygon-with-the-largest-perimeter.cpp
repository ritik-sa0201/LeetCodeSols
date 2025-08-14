class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
              pre[i]=nums[i]+pre[i-1];
        }
        for(int i=n-1;i>=2;i--){
            if(nums[i]<pre[i-1])return pre[i];
        }
        return -1;
    }
};