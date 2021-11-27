// used the nth catalan number +dp approach to solve it
class Solution {
public:
    int uniqueBST(int n, vector<int>&vec)
    {
        int ans = 0;
        if(n==0|| n==1) return 1;
        if(vec[n]!=-1)return vec[n];
        for(int i=0;i<n;i++)
            ans += uniqueBST(i,vec)*uniqueBST(n-i-1,vec);
        return vec[n]=ans;
            
    }
    int numTrees(int n) {
        vector<int>vec(n+1,-1);
        return uniqueBST(n,vec);
        
    }
};