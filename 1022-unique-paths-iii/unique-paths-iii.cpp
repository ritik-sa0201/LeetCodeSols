class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int totalToVisit = 0;

    int count(int x, int y, int ex, int ey, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& visited, int steps) {
     
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1 || visited[x][y] == 1)
            return 0;

  
        if (x == ex && y == ey) {
            return (steps == totalToVisit) ? 1 : 0; 
        }

        visited[x][y] = 1;
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            ans += count(nx, ny, ex, ey, m, n, grid, visited, steps + 1);
        }
        visited[x][y] = -1;  
        return ans;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx = -1, sy = -1, ex = -1, ey = -1;
        int m = grid.size();
        int n = grid[0].size();

     
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) totalToVisit++;
                if (grid[i][j] == 1) sx = i, sy = j;
                if (grid[i][j] == 2) ex = i, ey = j;
            }
        }

        vector<vector<int>> visited(m, vector<int>(n, -1));
        return count(sx, sy, ex, ey, m, n, grid, visited, 1); 
    }
};
