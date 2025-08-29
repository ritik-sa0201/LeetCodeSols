// // class Solution {
// public:
//     int n;
//     vector<vector<int>> dp;

//     bool isPred(string &a, string &b) {
//         if (b.size() != a.size() + 1) return false;
//         int i = 0, j = 0;
//         while (i < a.size() && j < b.size()) {
//             if (a[i] == b[j]) i++;
//             j++;
//         }
//         return i == a.size();
//     }

//     int solve(int i, int prev, vector<string>& words) {
//         if (i == n) return 0;
//         if (dp[i][prev+1] != -1) return dp[i][prev+1];

//         int take = 0;
//         if (prev == -1 || isPred(words[prev], words[i])) {
//             take = 1 + solve(i+1, i, words);
//         }
//         int skip = solve(i+1, prev, words);

//         return dp[i][prev+1] = max(take, skip);
//     }

//     int longestStrChain(vector<string>& words) {
//         n = words.size();
//         sort(words.begin(), words.end(), [](string &a, string &b) {
//             return a.size() < b.size();
//         });

//         dp.assign(n, vector<int>(n+1, -1));
//         return solve(0, -1, words);
//     }
// };

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

    // // int solve(int i, int prev, vector<string>& words) {
    //     if (i == n) return 0;
    //     if (dp[i][prev+1] != -1) return dp[i][prev+1];

    //     int take = 0;
    //     if (prev == -1 || isPred(words[prev], words[i])) {
    //         take = 1 + solve(i+1, i, words);
    //     }
    //     int skip = solve(i+1, prev, words);

    //     return dp[i][prev+1] = max(take, skip);
    // }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });

        dp.assign(n+1, vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>=-1;prev--){
                int take = 0;
                if (prev == -1 || isPred(words[prev], words[i])) {
                    take = 1 + dp[i+1][i+1];
                }
                int skip = dp[i+1][prev+1];
              
                dp[i][prev+1] = max(take, skip);
            }
        }
        return dp[0][0];
    }
};
