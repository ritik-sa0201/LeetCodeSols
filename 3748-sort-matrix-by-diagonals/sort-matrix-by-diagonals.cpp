class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        priority_queue<int>maxh;
        int m=grid.size(),n=grid[0].size();
            for(int i=0;i<m;i++){
                int x=i;
                int y=0;
                while(x>=0 && x<m){
                   maxh.push(grid[x][y]);
                   x++;y++;
                }
                x=i;y=0;
                while(!maxh.empty()){
                    grid[x][y]=maxh.top();
                    maxh.pop();
                    x++;y++;
                }
            }
            priority_queue<int,vector<int>,greater<int>>minh;
            for(int i=1;i<n;i++){
                  int x=0,y=i;
                  while(y>=0 && y<n){
                    minh.push(grid[x][y]);
                    x++;
                    y++;
                  }
                  x=0,y=i;
                  while(!minh.empty()){
                    grid[x][y]=minh.top();
                    minh.pop();
                    x++;y++;
                }
            }
            return grid;
    }
};