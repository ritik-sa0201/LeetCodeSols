class Solution {
    int solve(vector<int>& piles, int i, int j, bool f, vector<vector<int>> &dp) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (f) {
       
            int takeLeft  = piles[i] + solve(piles, i + 1, j, !f, dp);
            int takeRight = piles[j] + solve(piles, i, j - 1, !f, dp);
            dp[i][j] = max(takeLeft, takeRight);
        } else {
   
            int takeLeft  = solve(piles, i + 1, j, !f, dp) - piles[i];
            int takeRight = solve(piles, i, j - 1, !f, dp) - piles[j];
            dp[i][j] = min(takeLeft, takeRight);
        }

        return dp[i][j];
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(piles, 0, n - 1, true, dp) > 0;
    }
};
