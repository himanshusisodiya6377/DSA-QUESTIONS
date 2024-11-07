class Solution {
public:
bool prime(int n){
    if (n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int prod(int n,vector<int>&v){
    int sum=0;
    int pre=n;
  
    while(n>1){
    for(int i=0;i<v.size();i++){
         if(n%v[i]==0) {
            sum+=v[i];
            n/=v[i];
         }
    }
    }
   if(pre==sum) return sum;
   else return prod(sum,v);
}
    int smallestValue(int n) {
        vector<int>v;
        int pre;
        for(int i=2;i<=n;i++){
            if(prime(i)) v.push_back(i);
        }
        return prod(n,v);
    }
};