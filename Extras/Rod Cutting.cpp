
class Solution{
  public:
  int maxprofit(int prices[],int n ,int curr,vector<vector<int>>&vec)
  {
      if(n==0) return 0;
      if(curr>=n) return 0;
      if(vec[curr][n]!=-1) return vec[curr][n];
      int consider = 0;
      int len = curr+1;
      if(len<=n)
      {
          consider = prices[curr]+maxprofit(prices,n-len,curr,vec);
      }
      int notconsider = maxprofit(prices,n,curr+1,vec);
      return vec[curr][n]=max(consider,notconsider);
  }
    int cutRod(int price[], int n) {
        vector<vector<int>>vec(1002,vector<int>(1002,-1));
        return maxprofit(price,n,0,vec);
       
    }
};