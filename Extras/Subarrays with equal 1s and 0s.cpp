class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        unordered_map<long,long> mp;
        
        long long int prefixSum=0;
        long long int ans=0;
        mp[prefixSum]=1;
        for (int i=0;i<n;i++){
            int currval = arr[i];
            if(currval == 0)
           {
               prefixSum+=-1;  // making it similar to zero sum subarrays
           }
           else 
             prefixSum+=1;
           // prefixSum +=currval;
            
            if(mp.find(prefixSum)!=mp.end())
             {
                 ans += mp[prefixSum];
                 mp[prefixSum]+=1;
             }
             else
             mp[prefixSum]=1;
        }
        return ans;
    }
};