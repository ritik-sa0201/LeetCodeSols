class Solution {
    vector<pair<int,int>>dir={{1,1},{1,-1},{-1,-1},{-1,1}};
    int dp[500][500][4][2];
    int memo(int x,int y,int target,bool allowed,int d,vector<vector<int>>& grid){
        int dx=x+dir[d].first,dy=y+dir[d].second;
        if(dx<0 || dy<0 || dx>=grid.size() || dy>=grid[0].size() || grid[dx][dy]!=target) return 0;
        if(dp[dx][dy][d][allowed]!=-1) return dp[dx][dy][d][allowed];
        int no_turn=1+memo(dx,dy,2-target,allowed,d,grid);
        int take=0;
        if(allowed){
            take=1+memo(dx,dy,2-target,!allowed,(d+1)%4,grid);
        }
        return dp[dx][dy][d][allowed]=max(no_turn,take);
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),res=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int d=0;d<4;d++){
                        res=max(res,1+memo(i,j,2,true,d,grid));
                    }
                }
            }
        }
        return res;
    }
};