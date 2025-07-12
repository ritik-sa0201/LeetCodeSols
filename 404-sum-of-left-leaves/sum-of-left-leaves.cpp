class Solution {
    void solve(TreeNode* root, int &sum) {
        if (!root) return;

        if (root->left && !root->left->left && !root->left->right) {
            sum += root->left->val;
        }

        solve(root->left, sum);
        solve(root->right, sum);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};
