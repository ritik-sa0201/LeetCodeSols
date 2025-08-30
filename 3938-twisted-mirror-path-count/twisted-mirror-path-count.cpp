class Solution {
public:
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    int mod = 1e9+7;
    vector<vector<vector<long long>>> dp;

    long long solve(int i, int j, int m, int n, int d, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1) return 1;
        if (dp[i][j][d + 1] != -1) return dp[i][j][d + 1];

        long long ans = 0;

        if (grid[i][j] == 1) {
           
            int nx = i + dx[d];
            int ny = j + dy[d];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                ans = (ans + solve(nx, ny, m, n, !d, grid)) % mod;
            }
        } else {
           
            for (int k = 0; k < 2; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (grid[nx][ny] == 1) {
                        ans = (ans + solve(nx, ny, m, n, !k, grid)) % mod;
                    } else {
                        ans = (ans + solve(nx, ny, m, n, k, grid)) % mod;
                    }
                }
            }
        }

        return dp[i][j][d + 1] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m, vector<vector<long long>>(n, vector<long long>(3, -1)));
        return solve(0, 0, m, n, -1, grid) % mod;
    }
};
