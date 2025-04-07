class Solution {
public:
    bool isPowerOfFour(int n) {
    //     if (n == 1)
    //         return true;
    //    long long int x=log2(abs((long long)n));
    //    return pow(2,x)==abs((long long)n);
    //TC-O(n)
    //  long long int x=abs((long long )n);
    //  if(n<4 && n!=1) return false;
    //  while(n%4==0){
    //     n/=4;
    //  }
    //  return n==1;
    if(n==1) return true;
    if(n<4 || n%4!=0) return false;
    return isPowerOfFour(n/=4);
    }
};