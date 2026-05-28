class Solution {
public:
    bool isUgly(int n) {
            if(n==1) return true;
        
           while(n>0 && n%2==0){
            n/=2;
           }

           while(n>0 && n%3==0) n/=3;
           while(n>0 && n%5==0) n/=5;

           return n==1;
    }
};