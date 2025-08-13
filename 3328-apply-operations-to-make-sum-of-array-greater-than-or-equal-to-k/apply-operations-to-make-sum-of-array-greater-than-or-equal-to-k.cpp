class Solution {
public:
    int minOperations(int k) {
        if (k == 1) return 0;

        int ans = INT_MAX;


        for (int n = 1; n <= k; n++) {
            int steps = n - 1; 
             steps +=ceil(k/(n*1.0));
            ans = min(ans, steps);
        }
        return ans-1;
    }
};
