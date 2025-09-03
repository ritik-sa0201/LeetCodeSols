class Solution {
    int n;
    vector<int>dp;
    int solve(int i,vector<int>&days,vector<int>&costs){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
      int mini=INT_MAX;
        for(int idx=0;idx<3;idx++){
            if(idx==0){
               mini = min(mini,costs[idx] + solve(i+1,days,costs));
            }
            if(idx==1){
                int j=i;
                while(j<days.size() && days[j] <=days[i]+6){
                    j++;
                }
                mini = min(mini,costs[idx]+solve(j,days,costs));
            }
             if(idx==2){
                int j=i;
                while(j<days.size() && days[j] <=days[i]+29){
                    j++;
                }
                mini = min(mini,costs[2]+solve(j,days,costs));
            }
        }
        return dp[i]= mini;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        dp.resize(n+1,-1);
        return solve(0,days,costs);
    }
};