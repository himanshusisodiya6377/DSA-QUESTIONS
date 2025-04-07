class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 4 && n!=1)
            return false;
    if(n==1) return true;
    if(n%4!=0) return false;
       long long int x=log2(abs((long long)n));
       return pow(4,x/2)==abs((long long)n);
    //TC-O(n)
    //  long long int x=abs((long long )n);
    //  if(n<4 && n!=1) return false;
    //  while(n%4==0){
    //     n/=4;
    //  }
    //  return n==1;
    //recursive approach
    //TC-O(n) SC-O(n)
    // if(n==1) return true;
    // if(n<4 || n%4!=0) return false;
    // return isPowerOfFour(n/=4);
    }
};