class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        int v=x.size();
        int h=y.size();
        
        int verseg=1,horseg=1;
        
        priority_queue<pair<int,char>>pq;
        
        for(auto it : x) pq.push({it,'v'});
        for(auto it : y) pq.push({it,'h'});
        
        int ans=0;
        
        while(!pq.empty()){
              pair<int,char>p=pq.top();
              pq.pop();
              if(p.second=='v'){
                  ans+=(p.first*horseg);
                  verseg++;
              }
              else{
                  ans+=(p.first*verseg);
                  horseg++;
              }
        }
        
        return ans;
    }
};
