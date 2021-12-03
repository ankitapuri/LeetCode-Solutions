class Solution {
public:
    bool check(int n, vector<int>&vec)
    {
        if(n==1) return true;
        if(n<=0)return false;
        if(n%2==0) return check(n/2,vec);
        if(n%3==0)return check(n/3,vec);
        if(n%5==0)return check(n/5,vec);
        return false;
    }
    bool isUgly(int n) {
        vector<int>vec{2,3,5};
        return check(n,vec);
        
    }
};