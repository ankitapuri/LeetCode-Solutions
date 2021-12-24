class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<ll,ll> mp;
        
        ll prefixSum=0;
        ll ans=0;
        mp[prefixSum]=1;
        for (int i=0;i<n;i++){
            int currval = arr[i];
            prefixSum +=currval;
            
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