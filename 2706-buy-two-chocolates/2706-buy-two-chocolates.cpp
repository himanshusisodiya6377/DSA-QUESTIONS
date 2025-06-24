class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int temp=money;
        int i=0;
        while(i<2 && money>=0){
            money-=prices[i];
            i++;
        }
        if(money<0) return temp;
        else return money;
    }
};