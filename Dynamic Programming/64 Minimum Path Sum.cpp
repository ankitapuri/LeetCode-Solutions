class Solution {
public:
    int minsum(vector<vector<int>>& grid,int m,int n , int curr_row,int curr_col,vector<vector<int>>&t)
    {
        if(m-1==curr_row && n-1 ==curr_col) return grid[curr_row][curr_col];
        if(curr_row >= m || curr_col>= n) return 1000;
        if(t[curr_row][curr_col]!=-1) return t[curr_row][curr_col];
        int down = grid[curr_row][curr_col]+minsum(grid,m,n,curr_row,curr_col+1,t);
        int right = grid[curr_row][curr_col]+minsum(grid,m,n,curr_row+1,curr_col,t);
        return t[curr_row][curr_col]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>t(m, vector<int>(n, -1));
        return minsum(grid, m, n, 0, 0, t);
    }
};