class Solution {
public:
    int dp[1001][1001]; 

    int solve(int i, int lastIdx, vector<pair<int,int>>& p) {
        if (i == p.size()) return 0;
        if (dp[i][lastIdx+1] != -1) return dp[i][lastIdx+1];

        int take = 0;
        if (lastIdx == -1 || p[i].first > p[lastIdx].second) {
            take = 1 + solve(i+1, i, p);
        }
        int skip = solve(i+1, lastIdx, p);

        return dp[i][lastIdx+1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int m = pairs.size();
        vector<pair<int,int>> p;
        for (auto& x : pairs) p.push_back({x[0], x[1]});
        sort(p.begin(), p.end());

        memset(dp, -1, sizeof(dp));
        return solve(0, -1, p);
    }
};
