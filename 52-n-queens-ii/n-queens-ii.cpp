class Solution {
    bool isValid(int r, int c, int n, vector<string>& board) {
 
        for (int i = 0; i < r; i++) {
            if (board[i][c] == 'Q') return false;
        }


        for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

   
        for (int i = r-1, j = c+1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    int ans = 0;
    void solve(int r, int n, vector<string>& board) {
        if (r == n) {
            ans++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (isValid(r, c, n, board)) {
                board[r][c] = 'Q';
                solve(r + 1, n, board);
                board[r][c] = '.';
            }
        }
    }

public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, n, board);
        return ans;
    }
};
