class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        set<int> st(nums.begin(), nums.end()); 
        int maxi = 0;
        int prev = -1;

        for (int num : st) {
            if (prev != -1) {
                maxi = max(maxi, num - prev);
            }
            prev = num;
        }

        return maxi;
    }
};
