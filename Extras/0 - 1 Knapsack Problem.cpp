class Solution
{
    public:
    int maxProfit(int wt[],int val[],int cap,int n,int curr,unordered_map<string,int>&mp)
    {
        if(curr>=n)
        return 0;
        
    string curr_key = to_string(curr)  + "_"  + to_string(cap);
    
    if(mp.find(curr_key)!=mp.end())
    return mp[curr_key];
    
    int consider=0;
    
    if(wt[curr]<=cap)
    consider= val[curr] + maxProfit(wt,val,cap-wt[curr],n,curr+1,mp);
    
    
    int dontconsider = maxProfit(wt,val,cap,n,curr+1,mp);
    
    mp[curr_key]= max(consider,dontconsider);
    
    return mp[curr_key];
    }
    
int knapSack(int W, int wt[], int val[], int n) 
    { 
       unordered_map<string,int>mp;
       return maxProfit(wt,val,W,n,0,mp); 
    }

};