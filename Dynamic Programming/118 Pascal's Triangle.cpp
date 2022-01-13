class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        pascal(numRows,ans);
        return ans;
       
    }
    void pascal(int nrows,vector<vector<int>>&ans)
    {
       for(int i=0;i<nrows;i++)
       {
           ans[i].resize(i+1);  // its size is always one greater than the no of row in which we are 
           ans[i][0] = ans[i][i]=1;
           for(int j=1; j<i; j++)
           {
               ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
           }
       }
        return;
        }
};