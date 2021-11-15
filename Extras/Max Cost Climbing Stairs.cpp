class Solution {
public:
    unordered_map<int,int>mp;
    int maxcost(vector<int>&cost , int curr)
    {
        if (curr == cost.size())
            return 0;
        if (curr > cost.size())
            return INT_MIN;
        if(mp.find(curr)!=mp.end())
            return mp[curr];
        int onejump = cost[curr]+maxcost(cost,curr+1);
        int twojump = cost[curr]+maxcost(cost,curr+2);
        int currkey = curr;
        mp[currkey] = max(onejump,twojump);
        return max(onejump,twojump);
        
    }
    int maxCostClimbingStairs(vector<int>& cost) {
        int a = maxcost(cost,0);
        int b = maxcost(cost,1);
        return max(a,b);
        
    }
};