class Solution{
  public:
    int maxLen(int A[], int n)
    {
        // Your code here
        unordered_map<int,int>mp;
        int prefixsum=0;
        int ans = 0;
        mp[prefixsum]=-1;
       for(int i=0;i<n;i++)
       {
           int currval = A[i];
           if(currval == 0)
           {
               prefixsum+=-1;  // making it similar to longest subarray with 0 sum
           }
           else 
             prefixsum+=1;
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