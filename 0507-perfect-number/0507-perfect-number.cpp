class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=0;
        int n=num.size();
        if(n==1) return false;
        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0) {
                sum+=i;
               if(i!=1) sum+=(num/i);
        }
        }
        if(sum==num) return true;
        else return false;
    }
};