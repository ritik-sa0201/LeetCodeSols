class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        if (n == 1) return 0;

        int ans = 0;
        int i = 0, j = 1;

        while (j < n) {
            if (colors[i] == colors[j]) {
                if (neededTime[i] > neededTime[j]) {
                    ans += neededTime[j];
                    j++; 
                } else {
                    ans += neededTime[i];
                    i = j; 
                    j++;
                }
            } else {
                i = j; 
                j++;
            }
        }
        return ans;
    }
};
