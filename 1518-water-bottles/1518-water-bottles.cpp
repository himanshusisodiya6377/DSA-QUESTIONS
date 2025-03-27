class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int temp=numBottles;
        int ans=0;
        while(temp>0){
            int x=temp/numExchange;
            if(x==0) break;
            int y=temp%numExchange;
            ans+=x;
            temp=x+y;
        }
       return ans+numBottles;
    }
};