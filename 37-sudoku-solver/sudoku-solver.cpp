class Solution {
    bool check(vector<vector<char>>& board, int i, int j) {
        char curr = board[i][j];
        for (int r = 0; r < 9; r++) {
            if (r != i && board[r][j] == curr) return false;
        }

        for (int c = 0; c < 9; c++) {
            if (c != j && board[i][c] == curr) return false;
        }

        int srow = (i / 3) * 3;
        int scol = (j / 3) * 3;
        for (int r = srow; r < srow + 3; r++) {
            for (int c = scol; c < scol + 3; c++) {
                if ((r != i || c != j) && board[r][c] == curr) 
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char x = '1'; x <= '9'; x++) {
                        board[r][c] = x;
                        if (check(board, r, c) && solve(board)) {
                            return true;  
                        }
                        board[r][c] = '.';  
                    }
                    return false;  
                }
            }
        }
        return true; 
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
