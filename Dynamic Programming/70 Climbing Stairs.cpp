class Solution {
public:
    int totalways(int curr,int target,unordered_map<int,int>mp)
    {
        if(curr == target) return 1;
        if(curr>target) return 0;
        int currkey = curr;
        if(mp.find(currkey)!=mp.end())
          return mp[curr];
        int onestep = totalways(curr+1,target,mp);
        int twostep = totalways(curr+2,target,mp);
        mp[curr] = onestep+twostep;
        return onestep+twostep;
    }
     int climbStairs(int n) {
         unordered_map<int,int>mp;
         return totalways(0,n,mp);
     }   
    }
};
     