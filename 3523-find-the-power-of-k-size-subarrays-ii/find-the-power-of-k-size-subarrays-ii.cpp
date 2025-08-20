class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int j = 0; j < nums.size(); j++) {
        
            if (!dq.empty() && nums[j] != dq.back() + 1) {
                dq.clear();
            }

            dq.push_back(nums[j]);

            if (dq.size() > k) dq.pop_front();

            if (j >= k - 1) {
                if (dq.size() == k) ans.push_back(dq.back());
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};
