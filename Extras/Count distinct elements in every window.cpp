class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here.
        vector<int>res;
        int distinct_cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<k-1;i++)
        {
            int currval = arr[i];
            if(mp.find(currval)!=mp.end())
              mp[currval]+=1;
            else
             {mp[currval]=1;
             distinct_cnt+=1;}
        }
        int release = 0;
        for(int acquire = k-1;acquire<n;acquire++)
        {
            int currval = arr[acquire];
            if(mp.find(currval)!=mp.end())
            {
                mp[currval]+=1;
            }
            else
            {
                mp[currval]=1;
                distinct_cnt += 1;
            }
           
           res.push_back(distinct_cnt);
           int discard_val = arr[release];
           mp[discard_val]-=1;
           
           if(mp[discard_val]==0)
           {
               mp.erase(discard_val);
               distinct_cnt-=1;
           }
           release+=1;
        }
        return res;
    }
};