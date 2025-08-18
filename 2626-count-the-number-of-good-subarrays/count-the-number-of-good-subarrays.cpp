class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long ans = 0, pairs = 0;
        int i = 0, n = nums.size();

        for (int j = 0; j < n; j++) {
         
            pairs += freq[nums[j]];
            freq[nums[j]]++;

          
            while (pairs >= k) {
                ans += (n - j); 
                freq[nums[i]]--;
                pairs -= freq[nums[i]];
                i++;
            }
        }
        return ans;
    }
};
