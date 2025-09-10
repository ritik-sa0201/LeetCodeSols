class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        long long curr = 1;   
        int ans = 0;
        int i = 0;

        while (curr <= target) {
            if (i < coins.size() && coins[i] <= curr) {
                curr += coins[i];
                i++;
            } else {
                curr += curr;
                ans++;
            }
        }

        return ans;
    }
};
