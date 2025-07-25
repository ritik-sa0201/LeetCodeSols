class Solution {
   int dx[4] = {0,-1,0,1};
   int dy[4] = {-1,0,1,0};

   bool dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& visited,int x,string word){
    visited[i][j]=1;
     if(x==word.size()-1)return true;
     x = x+1;
    for(int k=0;k<4;k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx>=0 && nx < board.size() && ny>=0 && ny<board[0].size() && visited[nx][ny]==-1 && board[nx][ny]==word[x]){
            if(dfs(nx,ny,board,visited,x,word))return true;
        }
    }
    visited[i][j]=-1;
    return false;
   }


public:
    bool exist(vector<vector<char>>& board, string word) {
          int m = board.size();
          int n = board[0].size();
           int x = 0;
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]== word[x]){
                 vector<vector<int>>visited(m,vector<int>(n,-1));
                 if(dfs(i,j,board,visited,x,word))return true;
                }
            }
          }
          return false;
    }
};