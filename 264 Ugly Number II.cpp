class Solution {
public:
    int uglynum(int n,vector<int>&vec)
    {
        if(n==1)return true;
        if(n<=0) return false;
        int p2,p3,p5;
        p2=p3=p5=1;
        vec[1]=1;
        for(int i=2;i<=n;i++)
        {
            int two = vec[p2]*2;
            int three = vec[p3]*3;
            int five = vec[p5]*5;
            int ans = min(two,min(three,five));
            vec[i]=ans;
            if(ans == two)p2++;
            if(ans ==three)p3++;
            if(ans==five)p5++;
        }
        return vec[n];
    }
    int nthUglyNumber(int n) {
        vector<int>vec(n+2,-1);
        return uglynum(n,vec);
    }
};