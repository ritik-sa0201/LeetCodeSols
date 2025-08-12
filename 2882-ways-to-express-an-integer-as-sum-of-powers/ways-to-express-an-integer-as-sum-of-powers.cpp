class Solution {
    const int MOD = 1e9 + 7; 

    long long ipow(int base, int exp) {
        long long res = 1;
        for (int i = 0; i < exp; i++) {
            if (res > LLONG_MAX / base) return LLONG_MAX;
            res *= base;
        }
        return res;
    }

    long long countWays(int i, vector<long long>& nums, int n, vector<vector<long long>>& dp) {
        if (n == 0) return 1;
        if (i == 0) return 0;
        if (dp[i][n] != -1) return dp[i][n];

        long long ans = 0;
        if (nums[i - 1] <= n) {
            ans = (countWays(i - 1, nums, n - nums[i - 1], dp) % MOD
                 + countWays(i - 1, nums, n, dp) % MOD) % MOD;
        } else {
            ans = countWays(i - 1, nums, n, dp) % MOD;
        }

        return dp[i][n] = ans;
    }

public:
    int numberOfWays(int n, int x) {
        vector<long long> nums;
        for (int i = 1;; i++) {
            long long p = ipow(i, x);
            if (p > n) break;
            nums.push_back(p);
        }

        int size = nums.size();
        vector<vector<long long>> dp(size + 1, vector<long long>(n + 1, -1));
        return (int)(countWays(size, nums, n, dp) % MOD);
    }
};
