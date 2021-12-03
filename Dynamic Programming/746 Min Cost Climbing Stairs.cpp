class Solution {
public:
    unordered_map<int,int>mp;
    int mincost(vector<int>&cost , int curr)
    {
        if (curr == cost.size())
            return 0;
        if (curr > cost.size())
            return 1000;
        if(mp.find(curr)!=mp.end())
            return mp[curr];
        int onejump = cost[curr]+mincost(cost,curr+1);
        int twojump = cost[curr]+mincost(cost,curr+2);
        int currkey = curr;
        mp[currkey] = min(onejump,twojump);
        return min(onejump,twojump);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int a = mincost(cost,0);
        int b = mincost(cost,1);
        return min(a,b);
        
    }
};