class Solution {
    int m;
    vector<vector<int>> prefix;
    vector<vector<int>> dp;  

    int solve(int i, int k) {
        if (k == 0) return 0;
        if (i >= m) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int ans = solve(i+1, k);  
        int sz = prefix[i].size() - 1;
        for (int x = 1; x <= min(sz, k); x++) {
            ans = max(ans, prefix[i][x] + solve(i+1, k-x));
        }

        return dp[i][k] = ans;
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        m = piles.size();
        prefix.resize(m);
        for (int i = 0; i < m; i++) {
            int sz = piles[i].size();
            prefix[i].resize(sz+1, 0);
            for (int j = 0; j < sz; j++) {
                prefix[i][j+1] = prefix[i][j] + piles[i][j];
            }
        }

        dp.assign(m+1, vector<int>(k+1, -1));
        return solve(0, k);
    }
};
