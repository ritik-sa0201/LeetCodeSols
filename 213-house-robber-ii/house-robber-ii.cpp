class Solution {
    int solve(int i, int start, vector<int>& nums, vector<int>& dp) {
        if (i < start) return 0;
        if (dp[i] != -1) return dp[i];

        int rob = nums[i] + solve(i - 2, start, nums, dp);
        int skip = solve(i - 1, start, nums, dp);

        return dp[i] = max(rob, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        int case1 = solve(n - 2, 0, nums, dp1);

        vector<int> dp2(n, -1);
        int case2 = solve(n - 1, 1, nums, dp2);

        return max(case1, case2);
    }
};