class Solution {
public:
    bool isPowerOfThree(int n) {
    if(n<=0) return false;
     int num=pow(3,19);
     if(num%n==0) return true;
      return false;
    }
};