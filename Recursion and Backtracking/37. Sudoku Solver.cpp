class Solution {
public:
    bool isValidCell(vector<vector<char>>& board,int curr_row,int curr_col,int currval)
    {
        return isValidRow(board,curr_row,currval) && isValidCol(board,curr_col,currval) && isValidSubgrid(board,curr_row,curr_col,currval);
    }
    bool isValidRow(vector<vector<char>>& board,int curr_row,int currval)
    {
        for(int i=0;i<9;i++)
        {
            if(board[curr_row][i]== char(currval+'0'))
                return false;
        }
        return true;
    }
    bool isValidCol(vector<vector<char>>& board,int curr_col,int currval)
    {
        for(int i=0;i<9;i++)
        {
           if(board[i][curr_col] == char(currval+'0'))
                return false;
        }
        return true;
    }
    bool isValidSubgrid(vector<vector<char>>& board,int curr_row,int curr_col,int currval) 
        // need to find the starting point of every subgrid
    {
        int x = 3*(curr_row/3);
        int y = 3*(curr_col/3);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[x+i][y+j]== char(currval+'0'))
                    return false;
            }
        }
        return true;
    }
    
    bool SudukoSolver(vector<vector<char>>& board,int curr_row,int curr_col)
    {
        if(curr_row == 9)
            return true;
        int nextColPos,nextRowPos; 
        if(curr_col == 8)
        {
             nextRowPos = curr_row+1;
             nextColPos = 0;
        }
        else
        {
              nextRowPos = curr_row;
              nextColPos = curr_col+1;
        }
        if(board[curr_row][curr_col]!='.')
        {
            return SudukoSolver(board,nextRowPos,nextColPos);
        }
        for(int currval=1;currval<10;currval++)
        {
            if(isValidCell(board,curr_row,curr_col,currval))
            {
                board[curr_row][curr_col] = char(currval+'0');
                
                if(SudukoSolver(board,nextRowPos,nextColPos)==true)
                    return true;
                board[curr_row][curr_col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        SudukoSolver(board,0,0);
        return;
    }
};