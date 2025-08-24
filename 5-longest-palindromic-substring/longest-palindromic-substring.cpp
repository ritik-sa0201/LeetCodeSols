class Solution {
    vector<vector<int>> dp;

    int check(string &s, int i, int j) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = check(s, i + 1, j - 1);
        return dp[i][j] = false;
    }

public:
    string longestPalindrome(string s) {
        int si = 0;
        int maxlen = 1;
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j)) {
                    if (j - i + 1 > maxlen) {
                        maxlen = j - i + 1;
                        si = i;
                    }
                }
            }
        }

        return s.substr(si, maxlen);
    }
};
