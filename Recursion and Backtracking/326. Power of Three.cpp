class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true; //need to write it first else it might get missed
        if(n<=0 || n%3!=0) return false;
        return isPowerOfThree(n/3);
    }
};