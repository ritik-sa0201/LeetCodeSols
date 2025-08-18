class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                ans++;
                nums[i] ^= 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
            }
        }
        for (int x : nums) {
            if (x == 0) return -1;
        }
        return ans;
    }
};
