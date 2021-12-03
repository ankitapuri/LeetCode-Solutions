class Solution {
public:
    unordered_map<int,int>mp;
    int nthtrib(int n)
    {
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        int currkey = n;
        if(mp.find(currkey)!=mp.end())
            return mp[n];
        mp[n] = nthtrib(n-1)+nthtrib(n-2)+nthtrib(n-3);
        return mp[n];
    }
    
    int tribonacci(int n) {
    
        return nthtrib(n);
    }
};