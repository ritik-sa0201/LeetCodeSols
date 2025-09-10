class Solution {
    vector<vector<vector<int>>> dp;

    int score(int i, int j, int t, vector<int>& nums) {
        if (i > j) return 0;
        if (dp[i][j][t] != -1) return dp[i][j][t];

        if (t == 0) {  
            int pl = nums[i] + score(i + 1, j, 1, nums);
            int pr = nums[j] + score(i, j - 1, 1, nums);
            return dp[i][j][t] = max(pl, pr);
        } else { 
            int pl = score(i + 1, j, 0, nums);
            int pr = score(i, j - 1, 0, nums);
            return dp[i][j][t] = min(pl, pr);
        }
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int p1 = score(0, n - 1, 0, nums);
        int p2 = total - p1;
        return p1 >= p2;
    }
};
