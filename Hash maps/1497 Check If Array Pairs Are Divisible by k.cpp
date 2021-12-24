class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            int currval = arr[i];
            int currrem = ((currval%k)+k)%k;
            
            if(mp.find(currrem)!=mp.end())
                mp[currrem]+=1;
            else
                mp[currrem]=1;
        }
         for(auto it=mp.begin();it!=mp.end();it++){
            if(it->first==0)
            {
                if(mp[it->first]%2!=0)
                    return false;
            }
                else if(mp.find(k-it->first)==mp.end())
                    return false;
                else if (mp[it->first]!=mp[k-it->first])
                    return false;
            }
         return true;
    }
};
