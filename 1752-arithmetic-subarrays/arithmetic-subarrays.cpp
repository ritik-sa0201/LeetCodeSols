class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans;

        for (int i = 0; i < m; i++) {
            int st = l[i], ei = r[i];
            int len = ei - st + 1;
            if (len < 2) {
                ans.push_back(false);
                continue;
            }
            if (len == 2) {
                ans.push_back(true);
                continue;
            }
            vector<int> sub(nums.begin() + st, nums.begin() + ei + 1);
            sort(sub.begin(), sub.end());

            int d = sub[1] - sub[0];
            bool ok = true;
            for (int j = 2; j < len; j++) {
                if (sub[j] - sub[j - 1] != d) {
                    ok = false;
                    break;
                }
            }
            ans.push_back(ok);
        }
        return ans;
    }
};
