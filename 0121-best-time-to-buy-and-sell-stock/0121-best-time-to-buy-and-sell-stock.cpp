class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      int max=0;
      int diff=0;
      for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if((prices[j]-prices[i])>0){
            diff=(prices[j]-prices[i]);
            if(diff>max) max=diff;
        }
      }
      }
      return max;
    }
};