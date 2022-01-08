class Solution {
public:
    bool isValid(int curr_row,int curr_col,vector<vector<char>>&grid,int n)
    {
        return isRowValid(curr_row,grid,n) && isColValid(curr_col,grid,n) && areDiagValid(curr_row,curr_col,grid,n);
    }
    bool isRowValid(int curr_row,vector<vector<char>>&grid,int n)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[curr_row][j]=='Q')
                return false;
        }
        return true;
    }
    bool isColValid(int curr_col,vector<vector<char>>&grid,int n)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[j][curr_col]=='Q')
                return false;
        }
        return true;
     
    }
    bool areDiagValid(int curr_row,int curr_col,vector<vector<char>>&grid,int n)
    {
        int i = curr_row;
        int j = curr_col;
        while(i>=0 && j>=0) // first diag
        {
            if(grid[i][j]=='Q') return false;
            i--;
            j--;
        }
         i = curr_row;
         j = curr_col;
        while(i>=0 && j<n) // second diag
        {
            if(grid[i][j]=='Q') return false;
            i--;
            j++;
        }
         i = curr_row;
         j = curr_col;
        while(i<n && j>=0) // third diag
        {
            if(grid[i][j]=='Q') return false;
            i++;
            j--;
        }
         i = curr_row;
         j = curr_col;
        while(i<n && j<n) // fourth diag
        {
            if(grid[i][j]=='Q') return false;
            i++;
            j++;
        }
        return true;
    }
    vector<string>populate(vector<vector<char>>&grid,int n)
    {
        vector<string>vec;
        for(int currrow=0;currrow<n;currrow++)
        {
            string temp = "";
            for(int currcol=0;currcol<n;currcol++)
            {
                temp+=grid[currrow][currcol];
            }
            vec.push_back(temp);
        }
        return vec;
    }
    void solve(vector<vector<char>>&grid,int curr_row,int n , vector<vector<string>>&ans )
    {
        if(curr_row==n)
        {
            vector<string>tempans = populate(grid,n);
            ans.push_back(tempans);
            return;
        }
            for(int curr_col = 0;curr_col<n;curr_col++)
            {
                if(isValid(curr_row,curr_col,grid,n))
                {
                    grid[curr_row][curr_col]='Q';
                    solve(grid,curr_row+1,n,ans);
                    grid[curr_row][curr_col]='.'; // undoing the change and replacing it with dot
                }
            }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>grid(n,vector<char>(n,'.'));
        solve(grid,0,n,ans);
        return ans;
    }
};