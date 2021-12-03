class Solution {
public:
    
    int numsreq(int target , int curr,vector<vector<long>>&vec)
    {
        if(target == 0) return 0;
        if(target-(curr*curr)<0) return 10001;
        if(vec[curr][target]!=-1) return vec[curr][target];
        int consider = 10001;
        if(target-(curr*curr)>=0)
        {
            consider = 1+numsreq(target-(curr*curr),curr,vec);
        }
        int notconsider = numsreq(target,curr+1,vec);
        vec[curr][target]= min(consider,notconsider);
        return min(consider,notconsider);
    }
    int numSquares(int n) {
        vector<vector<long>>vec(sqrt(n)+10,vector<long>(n+1,-1));
        return numsreq(n,1,vec);
        
        
    }
};