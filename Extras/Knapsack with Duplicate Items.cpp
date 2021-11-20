class Solution{
public:
int MaxProfit(int wt[],int val[],int cap,int n,int curr, vector<vector<int>>&mp)
{
    if (cap ==0) return 0;
    if(curr>=n) return -1;
    
    if(mp[curr][cap]!= -1) return mp[curr][cap];
    int consider = 0;
    if(wt[curr]<=cap)
    {
        consider = val[curr]+MaxProfit(wt,val,cap-wt[curr],n,curr,mp);
    }
    int notconsider = MaxProfit(wt,val,cap,n,curr+1,mp);
    mp[curr][cap] =max(consider,notconsider);
    return max(consider,notconsider);
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>mp(1002,vector<int>(1002,-1));
        int profit = MaxProfit(wt,val,W,N,0,mp);
        if(profit == -1) return 0;
        return profit;
    }
};
