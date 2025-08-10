class Solution {
public:
    void buildTree(vector<int>& heights, int idx, int l, int r, vector<int>& st) {
        if (l == r) {
            st[idx] = heights[l];
            return;
        }
        int mid = (l + r) / 2;
        buildTree(heights, idx * 2 + 1, l, mid, st);
        buildTree(heights, idx * 2 + 2, mid + 1, r, st);
        st[idx] = max(st[idx * 2 + 1], st[idx * 2 + 2]);
    }

    int queryMax(int ql, int qr, int l, int r, int idx, vector<int>& st) {
        if (qr < l || ql > r) return INT_MIN; 
        if (ql <= l && r <= qr) return st[idx]; 
        int mid = (l + r) / 2;
        return max(queryMax(ql, qr, l, mid, idx * 2 + 1, st),
                   queryMax(ql, qr, mid + 1, r, idx * 2 + 2, st));
    }

 
    int findFirstGreater(int ql, int qr, int l, int r, int idx, vector<int>& st, vector<int>& heights, int target) {
        if (qr < l || ql > r || st[idx] <= target) return -1; 
        if (l == r) return l;
        int mid = (l + r) / 2;
        int leftAns = findFirstGreater(ql, qr, l, mid, idx * 2 + 1, st, heights, target);
        if (leftAns != -1) return leftAns;
        return findFirstGreater(ql, qr, mid + 1, r, idx * 2 + 2, st, heights, target);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> st(4 * n);
        buildTree(heights, 0, 0, n - 1, st);

        vector<int> ans;
        for (auto &q : queries) {
            int a = q[0], b = q[1];
            if (a > b) swap(a, b);
            if (a == b) {
                ans.push_back(a);
                continue;
            }
            if (heights[b] > heights[a]) {
                ans.push_back(b);
                continue;
            }

            int target = max(heights[a], heights[b]);
            int idx = findFirstGreater(b + 1, n - 1, 0, n - 1, 0, st, heights, target);
            ans.push_back(idx);
        }
        return ans;
    }
};
