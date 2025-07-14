class Solution {
public:
    void solve(int i, int n, int k, vector<int>& op, vector<vector<int>>& ans) {
   
        if (k == 0) {
            ans.push_back(op);
            return;
        }
   
        if (i > n) return;

    
        op.push_back(i);
        solve(i + 1, n, k - 1, op, ans);

      
        op.pop_back();
        solve(i + 1, n, k, op, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(1, n, k, op, ans);
        return ans;
    }
};
