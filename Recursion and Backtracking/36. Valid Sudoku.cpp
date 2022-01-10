class Solution {
public:
    bool solveSudoku(vector<vector<char>> &board, int row, int col) {
        // If the position is now at the end of the 9*9 grid
        if(row == 8 and col == 9) return true;
        // if column has reached upper bound
        if(col==9)  {
            row++;
            col=0;
        }
        // For characters other than dot move to the next position
        if(board[row][col]=='.') return solveSudoku(board,row,col+1); 
        char num=board[row][col];
        if(isValid(board, row, col, num)) {
            if(solveSudoku(board,row,col+1)) return true;
        }
        return false;
    }
    bool isValid(vector<vector<char>> &board, int row, int col, char num) {
        int i,j;
        /* Checking if its duplicated on the same row */
        for(i=0; i<9; i++) {
            if(i!= col && board[row][i] == num) {
                return false;
            }
        }
        /* Checking if its duplicated on the same col */
        for(i=0; i<9; i++) {
            if(i!=row && board[i][col] == num) {
                return false;
            }
        }
        /* Checking if its duplicated inside the 3*3 grid */
        int rowOffset=row-(row%3);
        int colOffset=col-(col%3);
        for(i=0; i<3;i++) {
            for(j=0;j<3;j++) {
                if((rowOffset+i)!=row && (colOffset+j)!=col && board[rowOffset+i][colOffset+j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if(solveSudoku(board, 0, 0)) return true;
        return false;
    }
};