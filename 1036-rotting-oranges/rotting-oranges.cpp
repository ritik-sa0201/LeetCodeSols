class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }

        int rotted = 0;
        int minutes = 0;
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {1, 0, -1, 0};

        while (!q.empty()) {
            int size = q.size();
            bool isRotted = false;

            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < grid.size() &&
                        ny >= 0 && ny < grid[0].size() &&
                        grid[nx][ny] == 1) {
                        
                        grid[nx][ny] = 2;
                        rotted++;
                        isRotted = true;
                        q.push({nx, ny});
                    }
                }
            }

            if (isRotted) minutes++;
        }

        return rotted == fresh ? minutes : -1;
    }
};
