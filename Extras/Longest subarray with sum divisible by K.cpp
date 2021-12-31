class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int ans=0 , prefixsum=0;
        unordered_map<int,int>mp;
        mp[prefixsum]=-1;
        for(int i=0;i<n;i++)
        {
            prefixsum+=arr[i]; 
            int rem = ((prefixsum%k)+k)%k;   // for handling negative cases as well
            if(mp.find(rem)!=mp.end())
            {
                int prevIndex = mp[rem];
                ans = max(ans,i-prevIndex);
            }
            else
                mp[rem]=i;
        }
        return ans;
	}
};