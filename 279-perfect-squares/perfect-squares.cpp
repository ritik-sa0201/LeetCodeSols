class Solution {
    int solve(int i, vector<int>& sqrs, int n, vector<vector<int>>& dp) {
        if (n == 0) return 0; 
        if (i >= sqrs.size()) return 1e9;     
        if (dp[i][n] != -1) return dp[i][n];

        int ans = 1e9;

        if (sqrs[i] <= n) {
            ans = min(ans, 1 + solve(i, sqrs, n - sqrs[i], dp));
        }
        ans = min(ans, solve(i + 1, sqrs, n, dp));

        return dp[i][n] = ans;
    }

public:
    int numSquares(int n) {
        int x = sqrt(n);
        vector<int> sqrs;
        for (int i = 1; i <= x; i++) {
            sqrs.push_back(i * i);
        }

        vector<vector<int>> dp(sqrs.size(), vector<int>(n + 1, -1));
        return solve(0, sqrs, n, dp);
    }
};
