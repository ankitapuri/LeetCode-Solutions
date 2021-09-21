class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int>res;
        int n = mat.size();
        int m = mat[0].size();
         if(m==1&& n==1) {
             res.push_back(0);
             res.push_back(0);
         }
        int pos_i = 0;
        int pos_j = 0;
        int max = mat[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(mat[i][j]>max)
               {
                   max = mat[i][j];
                   pos_i = i;
                   pos_j = j;
               }
            }
        }
        res.push_back(pos_i);
        res.push_back(pos_j);
        return res;
    }
};