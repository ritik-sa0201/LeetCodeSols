class Solution {
    int maxn, mini;
    vector<int> gp;
    vector<vector<vector<int>>> dp;

    int solve(int i, int sum, int curr, vector<int>& profit) {
        if (i == profit.size()) {
            return (curr >= mini) ? 1 : 0;
        }

        if (dp[i][sum][curr] != -1) return dp[i][sum][curr];

        long long count = 0;

        if (sum + gp[i] <= maxn) {
            int newProfit = min(mini, curr + profit[i]); 
            count += solve(i + 1, sum + gp[i], newProfit, profit);
        }

        count += solve(i + 1, sum, curr, profit);

        return dp[i][sum][curr] = count % 1000000007; 
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        maxn = n;
        mini = minProfit;
        gp = group;

        dp.assign(profit.size() + 1,
                  vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));

        return solve(0, 0, 0, profit);
    }
};
