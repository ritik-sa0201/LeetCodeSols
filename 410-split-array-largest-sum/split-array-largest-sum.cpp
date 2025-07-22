class Solution {
    // Can we split array into ≤ k parts with max subarray sum ≤ mid?
    bool isValid(vector<int>& nums, int k, int mid) {
        int count = 1;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (currSum + nums[i] > mid) {
                count++;
                currSum = nums[i];
            } else {
                currSum += nums[i];
            }
        }
        return count <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int si = *max_element(nums.begin(), nums.end()); 
        int ei = accumulate(nums.begin(), nums.end(), 0); 
        int ans = ei;

        while (si <= ei) {
            int mid = si + (ei - si) / 2;

            if (isValid(nums, k, mid)) {
                ans = mid;
                ei = mid - 1;
            } else {
                si = mid + 1;
            }
        }

        return ans;
    }
};
