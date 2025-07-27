class Solution {
    bool isSubsequenceDP(string a, string b) {
        int m = a.size();
        int n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n] == m; 
    }

public:
    int findLUSlength(vector<string>& strs) {
        int maxm = -1;

        for (int i = 0; i < strs.size(); i++) {
            bool isUncommon = true;

            for (int j = 0; j < strs.size(); j++) {
                if (i == j) continue;
                if (isSubsequenceDP(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }

            if (isUncommon) {
                maxm = max(maxm, (int)strs[i].length());
            }
        }

        return maxm;
    }
};
