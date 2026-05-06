class Solution {
public:
    vector<int>prime;
    bool check(int n){
        for(int i=2;i*i<n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    bool flag=false;

    void seive(){
        prime.resize(1001,0);
        prime[0]=prime[1]=-1;
        flag=true;
        for(int i=2;i<=1000;i++){
            if(prime[i]==-1) continue;
            if(check(i)){
                prime[i]=1;
                for(int j=i*i;j<1001;j*=i){
                    prime[j]=-1;
                }
            }
        }
    }
    
    int sumOfPrimesInRange(int n) {
        if(!flag) seive();
        
        string s=to_string(n);
        reverse(s.begin(),s.end());

        int rev=stoi(s);

        int sum=0;

        for(int i=min(n,rev);i<=max(n,rev);i++){
            if(prime[i]==1) sum+=i;
        }

        return sum;
    }
};