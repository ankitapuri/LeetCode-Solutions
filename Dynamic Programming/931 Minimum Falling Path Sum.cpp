class Solution {
public:
    int path(int n, int curr_row,int curr_col,vector<vector<int>>& matrix,vector<vector<int>>&vec)
    {
        if(curr_row>=n || curr_col>=n || curr_col<0 || curr_row<0) return 10000;
        if(curr_row==n-1)  return matrix[curr_row][curr_col];
        if(vec[curr_row][curr_col] != -1)  return vec[curr_row][curr_col];
        int d = matrix[curr_row][curr_col]+path(n,curr_row+1,curr_col,matrix,vec);
        int dl = matrix[curr_row][curr_col]+path(n,curr_row+1,curr_col-1,matrix,vec);
        int dr = matrix[curr_row][curr_col]+path(n,curr_row+1,curr_col+1,matrix,vec);
        return vec[curr_row][curr_col] = min(d,min(dl,dr));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int ans = 10000;
        vector<vector<int>>vec(102,vector<int>(102,-1));
        for(int i=0;i<n;i++)
        {
            ans = min(ans,path(n,0,i,matrix,vec));
        }
        return ans;
    }
};
