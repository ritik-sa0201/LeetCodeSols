class Solution {

    int solve(int i,int m,int t, vector<int>&piles, vector<vector<vector<int>>>&dp){
        if(i==piles.size()){
            return 0;
        }
        if(dp[i][m][t] != -1) return dp[i][m][t];

        int n = piles.size();
        int ans = 0;

        if(t==0){
            int sum=0;
            for(int j=i;j<n && j<i+2*m;j++){
                sum+=piles[j];
                ans = max(ans,sum+solve(j+1,max(m,j-i+1),1,piles,dp));
            }
        } else { 
            ans = INT_MAX;
            int sum=0;
            for(int j=i;j<n && j<i+2*m;j++){
                sum+=piles[j];
                ans = min(ans,solve(j+1,max(m,j-i+1),0,piles,dp));
            }
        }

        return dp[i][m][t] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2,-1)));
        return solve(0,1,0,piles,dp);
    }
};
