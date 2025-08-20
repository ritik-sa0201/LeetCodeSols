class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<pair<int,int>> ms;
        int ans = 0;
        int i = 0, j = 0;

        while (j < nums.size()) {
            ms.insert({nums[j], j});
            while (ms.rbegin()->first - ms.begin()->first > limit) {
                ms.erase(ms.find({nums[i], i}));
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
