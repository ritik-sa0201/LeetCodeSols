class Solution {
    int bs(int start, int target, vector<int>& nums) {
        int i = start, j = nums.size();
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= target) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }

public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int target = nums[i] + nums[j];
                int k = bs(j + 1, target, nums);
                ans += (k - (j + 1));
            }
        }
        return ans;
    }
};
