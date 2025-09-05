class Solution {
    int n;
    vector<int> dp;

    int solve(int i, vector<int>& piles){
        if(i == n) return 0;
        if(dp[i] != INT_MIN) return dp[i];

        int sum = 0, ans = INT_MIN;
        for(int j = i; j < n && j < i + 3; j++){
            sum += piles[j];
            ans = max(ans, sum - solve(j+1, piles));
        }
        return dp[i] = ans;
    }

public:
    string stoneGameIII(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, INT_MIN);
        int diff = solve(0, nums);
        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        else return "Tie";
    }
};
