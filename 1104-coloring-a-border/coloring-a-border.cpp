class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        int original = grid[row][col];
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> borders;
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            bool isBorder = false;

            for (int d = 0; d < 4; ++d) {
                int nr = r + dx[d];
                int nc = c + dy[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != original) {
                    isBorder = true;
                } else if (!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }

            if (isBorder) {
                borders.push_back({r, c});
            }
        }

        for (auto& [r, c] : borders) {
            grid[r][c] = color;
        }

        return grid;
    }
};
