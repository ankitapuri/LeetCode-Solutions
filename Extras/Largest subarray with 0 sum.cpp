class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>mp;
        int prefixsum=0;
        int ans = 0;
        mp[prefixsum]=-1;
       for(int i=0;i<n;i++)
       {
           int currval = A[i];
           prefixsum+=currval;
           if(mp.find(prefixsum)!=mp.end())
           {int temp = i-mp[prefixsum];
            ans = max(temp,ans);
           }
           else
           mp[prefixsum]= i;
       }
       return ans;
    }
};