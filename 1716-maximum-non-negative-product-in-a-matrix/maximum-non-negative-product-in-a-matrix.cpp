class Solution {
    typedef long long ll;
    const int MOD = 1e9 + 7;

    vector<vector<pair<ll,ll>>> dp;

    pair<ll, ll> solve(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        if (dp[i][j] != make_pair(LLONG_MAX, LLONG_MIN)) {
            return dp[i][j];
        }

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        // down
        if (i + 1 < m) {
            auto [downMax, downMin] = solve(i + 1, j, m, n, grid);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        // right
        if (j + 1 < n) {
            auto [rightMax, rightMin] = solve(i, j + 1, m, n, grid);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return dp[i][j] = {maxVal, minVal};
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        dp.assign(m, vector<pair<ll,ll>>(n, {LLONG_MAX, LLONG_MIN}));

        auto [maxVal, minVal] = solve(0, 0, m, n, grid);

        if (maxVal < 0) return -1;
        return (maxVal % MOD + MOD) % MOD;
    }
};
