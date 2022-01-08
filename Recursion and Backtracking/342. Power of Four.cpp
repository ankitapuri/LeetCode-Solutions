class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true; //need to write it first else it might get missed
        if(n<=0 || n%4!=0) return false;
        return isPowerOfFour(n/4);
    }
};