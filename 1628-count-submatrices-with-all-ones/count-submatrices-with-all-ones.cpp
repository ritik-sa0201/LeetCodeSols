class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
          int m = mat.size(), n = mat[0].size();
          vector<int> h(n, 0);
          int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if(mat[i][j]==0)h[j]=0;
            else h[j]+=1;

        for (int j = 0; j < n; j++) {
            int mini = h[j];
            for (int k = j; k >= 0 && h[k] > 0; k--) {
                mini = min(mini, h[k]);
                ans += mini;
            }
        }
    }
    return ans;
    }
};