class Solution {
public:
bool prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
    bool isThree(int n) {
       int x=sqrt(n);
       if(prime(x) && (x*x==n)) return true;
       else return false;
    }
};