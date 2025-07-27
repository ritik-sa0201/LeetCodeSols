class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int MOD = 1e9 + 7;

    int dfs(int i, int j, int maxMove, int m, int n, vector<vector<vector<int>>>& dp) {
        if (i < 0 || j < 0 || i >= m || j >= n) return 1;  
        if (maxMove == 0) return 0;
        if (dp[i][j][maxMove] != -1) return dp[i][j][maxMove];

        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            ans = (ans + dfs(nx, ny, maxMove - 1, m, n, dp)) % MOD;
        }

        return dp[i][j][maxMove] = ans;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(startRow, startColumn, maxMove, m, n, dp);
    }
};
