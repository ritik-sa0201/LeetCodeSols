class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;


        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return bfs(i, j, grid);
                }
            }
        }

        return 0;  
    }

private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int bfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1; 

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

              
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0) {
                    perimeter++;
                }
                else if (grid[nx][ny] == 1) {
                    grid[nx][ny] = -1; 
                    q.push({nx, ny});
                }
            }
        }

        return perimeter;
    }
};
