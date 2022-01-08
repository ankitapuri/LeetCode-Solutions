class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true; //need to write it first else it might get missed
        if(n<=0 || n%2!=0) return false;
        return isPowerOfTwo(n/2);
    }
};