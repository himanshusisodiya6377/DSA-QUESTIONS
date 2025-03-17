class Solution {
public:
    int calculate(int num){
        int ans=0;
        while(num!=0){
            ans+=num%10;
            num/=10;
        }
        return ans;
    }
    int addDigits(int num) {
        while(num>9){
            num=calculate(num);
        }
        return num;
    }
};