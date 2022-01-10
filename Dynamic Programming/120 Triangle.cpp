class Solution {
public:
    
    int path(vector<vector<int>>& triangle,int curr_row,int curr_col,vector<vector<int>>&vec)
    {
        if(curr_row>=triangle.size() || curr_col>=triangle[curr_row].size() || curr_col<0 || curr_row<0) return 10000;
        if(curr_row==(triangle.size()-1))  return triangle[curr_row][curr_col];
        if(vec[curr_row][curr_col]!=-1) return vec[curr_row][curr_col];
        int d = triangle[curr_row][curr_col]+path(triangle, curr_row+1,curr_col,vec);
        int dr = 100000;
        if((curr_col + 1) < (triangle[curr_row].size() + 1)){
         dr = triangle[curr_row][curr_col]+path(triangle,curr_row+1,curr_col+1,vec);
        }
        return vec[curr_row][curr_col] = min(d,dr);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>vec(202,vector<int>(202,-1));
        return path(triangle,0,0,vec);
    }
};