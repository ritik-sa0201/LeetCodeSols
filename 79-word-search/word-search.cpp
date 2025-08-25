class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool dfs(int i, int j, int m, int n, vector<vector<char>>& board,
             vector<vector<int>>& visited, int x, string& word) {
        if (board[i][j] != word[x]) return false;
        if (x == word.size() - 1) return true;
        
        visited[i][j] = 1;
        bool ans = false;
        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d], nj = j + dy[d];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && visited[ni][nj] == -1) {
                ans = ans || dfs(ni, nj, m, n, board, visited, x + 1, word);
                if (ans) break;
            }
        }
        visited[i][j] = -1;
        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> visited(m, vector<int>(n, -1));
                    if (dfs(i, j, m, n, board, visited, 0, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
