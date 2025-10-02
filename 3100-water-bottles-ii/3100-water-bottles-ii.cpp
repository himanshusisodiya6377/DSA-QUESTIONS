class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        while(numBottles>0){
           if(numBottles<numExchange){
            ans+=numBottles;
            numBottles=0;
           }
           else{
            numBottles-=numExchange;
            numBottles++;
            ans+=numExchange;
            numExchange++;
           }
        }
        return ans;
    }
};