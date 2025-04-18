class Solution {
public:
    bool checkPowersOfThree(int n) {
        //first approach 
        // int ans = 1;
        // int m = 0;
        // while (ans <n) {
        //     ans *= 3;
        //     if (ans > n) {
        //         ans /= 3;
        //         break;
        //     }
        //     m++;
        // }
        // n -= ans;
        // m--;
        // while (n > 0 && m >= 0) {
        //     int x = pow(3, m);
        //     if (x <= n)
        //         n -= x;
        //     m--;
        // }
        // if (n == 0)
        //     return true;
        // else
        //     return false;
        
        //second
        while(n>0){
            if(n%3>1) return false;
            n/=3;
        } 
        return true;
    }
};