class Solution {
    int n;
    vector<vector<int>> dp;

    int solve(int i, int t, vector<int>& piles) {
        if (i == n) return 0;

        if (dp[i][t] != INT_MIN) return dp[i][t];

        if (t == 0) { 
            int sum = 0, ans = INT_MIN;
            for (int j = i; j < n && j < i + 3; j++) {
                sum += piles[j];
                ans = max(ans, sum + solve(j + 1, 1, piles));
            }
            return dp[i][t] = ans;
        } else { 
            int ans = INT_MAX;
            for (int j = i; j < n && j < i + 3; j++) {
                ans = min(ans, solve(j + 1, 0, piles));
            }
            return dp[i][t] = ans;
        }
    }

public:
    string stoneGameIII(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(2, INT_MIN));

        int total = 0;
        for (int x : nums) total += x;

        int alice = solve(0, 0, nums);
        int bob = total - alice;

        if (alice > bob) return "Alice";
        else if (alice < bob) return "Bob";
        else return "Tie";
    }
};
