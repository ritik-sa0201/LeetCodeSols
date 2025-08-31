class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board[0].size();
        const int MOD = 1e9+7;

        vector<vector<int>> dp(m, vector<int>(n, -1));   
        vector<vector<int>> cnt(m, vector<int>(n, 0));   

     
        dp[m-1][n-1] = 0; 

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(board[i][j] == 'X') continue;
                if(i==m-1 && j==n-1) continue; 

                int val = (board[i][j]=='E' ? 0 : board[i][j]-'0');
                int best = -1;

                if(i+1<m && dp[i+1][j]!=-1) best = max(best, dp[i+1][j] + val);
                if(j+1<n && dp[i][j+1]!=-1) best = max(best, dp[i][j+1] + val);
                if(i+1<m && j+1<n && dp[i+1][j+1]!=-1) best = max(best, dp[i+1][j+1] + val);

                dp[i][j] = best;
            }
        }

        if(dp[0][0] == -1) return {0,0}; 

  
        cnt[m-1][n-1] = 1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(dp[i][j] == -1) continue;
                if(i==m-1 && j==n-1) continue;

                int val = (board[i][j]=='E' ? 0 : board[i][j]-'0');

                if(i+1<m && dp[i+1][j]!=-1 && dp[i+1][j]+val == dp[i][j]) {
                    cnt[i][j] = (cnt[i][j] + cnt[i+1][j]) % MOD;
                }
                if(j+1<n && dp[i][j+1]!=-1 && dp[i][j+1]+val == dp[i][j]) {
                    cnt[i][j] = (cnt[i][j] + cnt[i][j+1]) % MOD;
                }
                if(i+1<m && j+1<n && dp[i+1][j+1]!=-1 && dp[i+1][j+1]+val == dp[i][j]) {
                    cnt[i][j] = (cnt[i][j] + cnt[i+1][j+1]) % MOD;
                }
            }
        }

        return {dp[0][0], cnt[0][0]};
    }
};
