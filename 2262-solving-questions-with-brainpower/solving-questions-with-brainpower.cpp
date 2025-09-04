class Solution {
    vector<long long>dp;
    long long solve(int i,vector<vector<int>>& qs){
        if(i>=qs.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        long long pts =0;
        pts = max(pts,qs[i][0]+solve(i+qs[i][1]+1,qs));
        pts = max(pts,solve(i+1,qs));
        return dp[i] = pts;
    }
public:
    long long mostPoints(vector<vector<int>>& qs) {
        long long n=qs.size();
        dp.resize(n+1,-1);
        return solve(0,qs);
    }
};