class Solution {

    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};

    void dfs(int i,int j,int m,int n,vector<vector<int>>&visited,vector<vector<int>>&grid,int &val){
        visited[i][j]=1;
        val++;
        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(nx>=0 && nx<m && ny>=0 && ny < n && visited[nx][ny]==-1 && grid[nx][ny]==1){
             dfs(nx,ny,m,n,visited,grid,val);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count  =0;
        vector<vector<int>>visited(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(visited[i][j]==-1 && grid[i][j]==1){
                int val = 0 ;
                dfs(i,j,m,n,visited,grid,val);
                count = max(val,count);
               }
            }
        }
        return count;
    }
};