class Solution {
public:
    int largeSq(vector<vector<char>>& matrix,int curr_row,int curr_col,int m ,int n, unordered_map<string,int>&mp)
    {
        if(curr_row<0 || curr_row>=m || curr_col<0 || curr_col>=n || matrix[curr_row][curr_col]=='0') return 0;
        string currkey = to_string(curr_row)+"_"+to_string(curr_col);
        if(mp.find(currkey)!=mp.end()) return mp[currkey];
        int right = 1+largeSq(matrix,curr_row,curr_col+1,m,n,mp);
        int down = 1+largeSq(matrix,curr_row+1,curr_col,m,n,mp);
        int diagright = 1+largeSq(matrix,curr_row+1,curr_col+1,m,n,mp);
        return mp[currkey]=min(right,min(down,diagright));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string,int>mp;
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            { 
                if(matrix[i][j]=='1')
                 ans = max(ans,largeSq(matrix,i,j,m,n,mp));
            }
        }
        return ans*ans;
    }
};