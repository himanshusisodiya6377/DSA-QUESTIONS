class Solution {
public:
    #define M 1000000007
    long long modPow(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}
    int countGoodNumbers(long long n) {
      if(n%2==0) return ((modPow(5,n/2,M)%M)*(modPow(4,n/2,M)%M))%M;
      else return ((modPow(5,n/2+1,M)%M)*(modPow(4,n/2,M)%M))%M;
    }
};