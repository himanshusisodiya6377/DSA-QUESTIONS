class Solution {
public:
void prime( vector<bool>&sieve,int n){
    for(int i=2;i<=sqrt(n);i++){
        if(sieve[i]==1){
            for(int j=2*i;j<=n;j+=i){
                sieve[j]=0;
            }
        }
    }
}
    int countPrimes(int n) {
        int count=0;
        vector<bool>sieve(n+1,1);
        sieve[0]=0;
        sieve[1]=0;
        prime(sieve,n);
        for(int i=0;i<n;i++){
            if(sieve[i]==1) count++;
        }
        return count;
    }
};