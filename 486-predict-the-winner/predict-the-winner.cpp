class Solution {
    int score(int i, int j, int t, vector<int>& nums) {
        if (i > j) return 0;

        if (t == 0) {  
            int pl = nums[i] + score(i + 1, j, 1, nums);
            int pr = nums[j] + score(i, j - 1, 1, nums);
            return max(pl, pr);
        } else { 
            int pl = score(i + 1, j, 0, nums);
            int pr = score(i, j - 1, 0, nums);
            return min(pl, pr);
        }
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int p1 = score(0, nums.size() - 1, 0, nums);
        int p2 = total - p1;
        return p1 >= p2;
    }
};
