class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool isPred(string &a, string &b) {
        if (b.size() != a.size() + 1) return false;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) i++;
            j++;
        }
        return i == a.size();
    }

    int solve(int i, int prev, vector<string>& words) {
        if (i == n) return 0;
        if (dp[i][prev+1] != -1) return dp[i][prev+1];

        int take = 0;
        if (prev == -1 || isPred(words[prev], words[i])) {
            take = 1 + solve(i+1, i, words);
        }
        int skip = solve(i+1, prev, words);

        return dp[i][prev+1] = max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });

        dp.assign(n, vector<int>(n+1, -1));
        return solve(0, -1, words);
    }
};
