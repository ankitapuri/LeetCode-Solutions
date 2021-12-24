class Solution{
 public:
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        unordered_map<int,int>mp;
        int *res = new int [N];
        for(int i=0; i<N; i++)
        {
            if(mp.find(arr[i])!=mp.end())
              mp[arr[i]]+=1;
              else
              mp[arr[i]]=1;
        }
    for(int j=1; j<=N; j++)
      {
          if(mp.find(j)!=mp.end())
            res[j-1]=mp[j];
          else
          res[j-1]=0;
     }
      for(int k=0; k<N; k++)
      {
           arr[k]=res[k]; 
      }
    }
};