class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;
        for(int i=0;i<=1e3;i++){
            // i just x
            if(abs(n-i)<=k && ((n&i)==0)) sum+=i;
        }
        return sum;
    }
};