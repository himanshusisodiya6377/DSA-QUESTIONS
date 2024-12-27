class Solution {
public:
    bool isHappy(int n) {
        if(n==1) return true;
        else{
            int y;
            if(n>3)  y=n;
            else y=4;
            while(n>0){
                 int sum=0;
                while(n>0){
                   int x=n%10;
                   sum+=x*x;
                   n/=10;
                }
               if(sum==1) return true;
               else if(sum==y) return false;
               n=sum;
            }
        } 
        return false;
    }
};