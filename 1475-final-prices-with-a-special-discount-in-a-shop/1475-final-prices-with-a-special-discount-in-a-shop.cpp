class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
      int n=prices.size();
    vector<int>v(n,0);
    v[n-1]=prices[n-1];
    stack<int>idx;
    idx.push(n-1);
    for(int i=n-2;i>=0;i--){
      while(idx.size()>0 && prices[idx.top()]>prices[i]) {
        idx.pop();
      }
      if(idx.size()!=0) v[i]=prices[i]-prices[idx.top()];
      if(idx.size()==0) v[i]=prices[i];
      idx.push(i);
    } 
    return v; 
    }
};