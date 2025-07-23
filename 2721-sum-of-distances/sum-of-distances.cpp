class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);
        unordered_map<int, long long> sum_left, sum_right;
        unordered_map<int, long long> cnt_left, cnt_right;

        // Left to right pass
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            res[i] += cnt_left[x] * i - sum_left[x];
            cnt_left[x]++;
            sum_left[x] += i;
        }

        // Right to left pass
        for (int i = n - 1; i >= 0; --i) {
            int x = nums[i];
            res[i] += sum_right[x] - cnt_right[x] * i;
            cnt_right[x]++;
            sum_right[x] += i;
        }

        return res;
    }
};
