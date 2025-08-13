class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
       long long int ans = 1; 
        while (ans < n) {
            ans *= 3;
        }
        return ans == n;
    }
};
