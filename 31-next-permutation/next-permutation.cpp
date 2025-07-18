class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), l, r;
        for (l = n - 2; l >= 0; l--) {
            if (nums[l] < nums[l + 1]) break;
        }
        if (l < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (r = n - 1; r > l; r--) {
                if (nums[r] > nums[l]) break;
            }
            swap(nums[l], nums[r]);
            reverse(nums.begin() + l + 1, nums.end());
        }
    }
};
