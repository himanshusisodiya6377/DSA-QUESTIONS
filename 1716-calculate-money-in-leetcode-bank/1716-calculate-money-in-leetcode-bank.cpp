class Solution {
public:
    int totalMoney(int n) {
        int complete=n/7;
        int sum=0;
        for(int i=1;i<=complete;i++){
            sum+=(7*i+21);
        }
        int start=complete+1;
        int remday=n-7*complete;
        int presum=((start-1)*(start))/2;
        int suffsum=((start+remday-1)*(start+remday))/2;
        sum+=(suffsum-presum);
        return sum;
    }
};