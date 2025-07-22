class Solution {
public:
    vector<vector<int>> dp;

    bool check(const string &s, int i, int j) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = check(s, i + 1, j - 1);
        return dp[i][j] = false;
    }

    int countSubstrings(string s) {
        int n = s.length(), count = 0;
        dp.resize(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j)) count++;
            }
        }
        return count;
    }
};
