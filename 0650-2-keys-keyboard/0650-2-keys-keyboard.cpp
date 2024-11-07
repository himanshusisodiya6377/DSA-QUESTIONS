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
    int minSteps(int n) {
        vector<bool>sieve(n+1,1);
        int sum=0;
        sieve[0]=0;
        sieve[1]=0;
        prime(sieve,n);
        vector<int>v;
        for(int i=0;i<sieve.size();i++){
            if(sieve[i]==1) v.push_back(i);
        }
        for(int i=0;i<v.size();i++){
                 if(n%v[i]==0) sum+=v[i];
        }
        return sum;
    }
};