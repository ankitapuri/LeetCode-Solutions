class Solution {
public:
    int paths(vector<vector<int>>& obstacleGrid,int m,int n, int curr_row,int curr_col,vector<vector<int>>&t)
    {
       
        if(curr_row >= m || curr_col>= n) return 0;
        if (obstacleGrid[curr_row][curr_col]==1)return 0; // firstly we need to check that there is no 1 on the first and last position so this condition is written first. 
        if(m-1==curr_row && n-1==curr_col) return 1;
        if(t[curr_row][curr_col]!=-1) return t[curr_row][curr_col];
        int right = paths(obstacleGrid,m,n,curr_row+1,curr_col,t);
        int down = paths(obstacleGrid,m,n,curr_row,curr_col+1,t);
        t[curr_row][curr_col]= right+down;
        return right+down;
   }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        return paths(obstacleGrid, m, n, 0, 0, t);
    }
};

