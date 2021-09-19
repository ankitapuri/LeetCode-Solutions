class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
        int cnt=0;
        memset(prime,true,sizeof(prime));
        for(int i=2;i<=sqrt(n);i++)
        {
            if(prime[i]==true)
            {
                for(int j=i*2;j<=n;j+=i)
                {
                    prime[j] =false;
                }
            }
        }
        for(int i=2;i<n;i++)
       {
      if(prime[i]==true)
          cnt++;
        }
        return cnt;
   }
};