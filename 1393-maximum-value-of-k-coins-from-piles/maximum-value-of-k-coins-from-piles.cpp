class Solution {
    int m;
    vector<vector<int>> dp;

    int solve(int i, vector<vector<int>>& piles, int k) {
        if (k == 0) return 0;
        if(k<0)return -1e9;
        if (i >= m) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int ans = solve(i+1, piles, k); 
        int len = piles[i].size();
        int sum = 0;
        for (int idx = 0; idx <len; idx++) {
            sum += piles[i][idx];
            ans = max(ans, sum + solve(i+1, piles, k - (idx+1)));
        }

        return dp[i][k] = ans;
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        m = piles.size();
        dp.assign(m+1, vector<int>(k+1, -1));
        return solve(0, piles, k);
    }
};
