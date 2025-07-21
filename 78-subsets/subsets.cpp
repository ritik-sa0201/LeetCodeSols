class Solution {
    void solve(int i, vector<vector<int>>& ans, vector<int>& op, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(op);
            return;
        }

   
        solve(i + 1, ans, op, nums);

        
        op.push_back(nums[i]);
        solve(i + 1, ans, op, nums);
        op.pop_back();  
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans;
        vector<int> op;
        solve(0, ans, op, nums);
        return ans;
    }
};
