class Solution {
    int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int left = nums[i] - helper(i + 1, j, nums, dp);
        int right = nums[j] - helper(i, j - 1, nums, dp);

        return dp[i][j] = max(left, right);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, nums, dp) >= 0;
    }
};
