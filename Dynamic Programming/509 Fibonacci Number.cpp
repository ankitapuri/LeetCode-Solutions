class Solution {
public:
    unordered_map<int,int>mp;
    int nthfib(int n)
    {
        if(n==0 || n==1) return n;
        int currkey = n;
        if(mp.find(n)!=mp.end())
            return mp[n];
        mp[n]=fib(n-1)+fib(n-2);
        return mp[n];
    }
    
    int fib(int n) {
        return nthfib(n);
        
    }
};