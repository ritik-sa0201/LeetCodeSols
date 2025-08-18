class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, week = 0, count = 0;
        for (int i = 1; i <= n; i++) {
            count++;
            ans += count + week; 
            if (count == 7) {
                count = 0;
                week++;
            }
        }
        return ans;
    }
};
