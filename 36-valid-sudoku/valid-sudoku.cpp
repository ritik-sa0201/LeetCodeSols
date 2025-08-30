class Solution {
    bool solve(vector<vector<char>>& board, int i, int j) {
        char curr = board[i][j];
        if (curr == '.') return true; 

     
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

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !solve(board, i, j)) 
                    return false;
            }
        }
        return true;
    }
};
