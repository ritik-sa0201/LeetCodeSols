class Solution {
public:

    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

     int dfs(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>> &visited){
         visited[i][j]=1;
         int ans=grid[i][j];
           int maxi = INT_MIN;
        for(int d=0;d<4;d++){
            int nx = i+dx[d];
            int ny = j+dy[d];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=0 && visited[nx][ny]==-1){
                maxi = max(maxi,dfs(nx,ny,m,n,grid,visited));
            }
        }
        if(maxi!=INT_MIN)ans+=maxi;
        visited[i][j]=-1;
        return ans;
     }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n = grid[0].size();
        
        int maxi = INT_MIN;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]!=0){
                vector<vector<int>>vis(m,vector<int>(n,-1));
                maxi = max(maxi,dfs(i,j,m,n,grid,vis));
              }
            }
        }
         return maxi==INT_MIN?0:maxi;
    }
};