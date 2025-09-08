class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<long long> st(nums.begin(), nums.end());
        int ans = 1;
        for (int num : nums) {
            long long curr = num;
            int len = 1;
            
            while (st.find(curr * curr) != st.end()) {
                curr = curr * curr;
                len++;
            }
            ans = max(ans, len);
        }
        return ans >= 2 ? ans : -1;
    }
};
