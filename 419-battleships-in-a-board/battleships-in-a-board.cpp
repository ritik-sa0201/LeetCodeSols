class Solution {

    int dx[2] = {0,1};
    int dy[2] = {1,0};
     void dfs(int i,int j,int m,int n,vector<vector<int>>&visited,vector<vector<char>>&board,int right,int bottom){
          visited[i][j]=1;
          for(int d=0;d<2;d++){
            int nx = i+dx[d];
            int ny = j+dy[d];
            if(nx>=0 && nx<m && ny>=0 && ny<n && visited[nx][ny]==-1 && board[nx][ny]=='X'){
                    if(!right && !bottom){
                        if(nx == i+1){
                            dfs(nx,ny,m,n,visited,board,0,1);
                        }
                        else if(nx == i){
                             dfs(nx,ny,m,n,visited,board,1,0);
                        }
                    }
                    else if(right){
                       dfs(nx,ny,m,n,visited,board,1,0);
                    }
                    else if(bottom){
                        dfs(nx,ny,m,n,visited,board,0,1);
                    }
            }
          }
     }

public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size(),count=0;
        vector<vector<int>>visited(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==-1 && board[i][j]== 'X'){
                    dfs(i,j,m,n,visited,board,0,0);
                    count++;
                }
            }
        }
        return count;
    }
};