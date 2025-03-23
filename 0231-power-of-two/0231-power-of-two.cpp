class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        int x=__builtin_popcount(n);
        if(x==1) return true;
        else return false;
    }
};