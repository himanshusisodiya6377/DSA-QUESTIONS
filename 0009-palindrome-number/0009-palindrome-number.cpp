class Solution {
public:
int reverse(int x){
     long long int  prod=0;
    while(x>0){
        int z=x%10;
        prod+=z;
        x/=10;
        prod*=10;
    }
    return (prod/10);
}
    bool isPalindrome(int x) {
        if (x<0) return false;
        int y=reverse(x);
        if (y==x) return true;
        else return false;
    }
};