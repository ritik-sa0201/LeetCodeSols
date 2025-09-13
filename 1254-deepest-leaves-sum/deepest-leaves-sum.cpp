class Solution {
    int ht(TreeNode* root) {
        if (!root) return 0;
        int lh = ht(root->left);
        int rh = ht(root->right);
        return max(lh, rh) + 1;
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        int h = ht(root);
        int level = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* top = q.front();
                q.pop();

                if (level == h) { 
                    ans += top->val;
                }

                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            level++;
        }
        return ans;
    }
};
