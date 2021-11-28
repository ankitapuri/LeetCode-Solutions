class Solution {
public:
    int paths(int m,int n,int curr_row,int curr_col,unordered_map<string,int>&mp)
    {
        if(m-1==curr_row && n-1==curr_col) return 1;
        if(curr_row >= m || curr_col>= n) return 0;
        string currkey = to_string(curr_row)+"_"+to_string(curr_col);
        if(mp.find(currkey)!=mp.end())
            return mp[currkey];
        int right = paths(m,n,curr_row+1,curr_col,mp);
        int down = paths(m,n,curr_row,curr_col+1,mp);
        mp[currkey] = right+down;
        return right+down;
    }
    int uniquePaths(int m, int n) {
        unordered_map<string,int>mp;
        return paths(m,n,0,0,mp);
        
    }
};