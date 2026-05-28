class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        if(n==0) return false;
        int power=log2(n);
        if(pow(2,power)!=n) return false;
        return power%2==0;
    }
};