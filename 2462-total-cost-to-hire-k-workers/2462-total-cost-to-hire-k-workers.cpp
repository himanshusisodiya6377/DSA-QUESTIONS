class Solution {
public:
    typedef pair<long long,long long> p;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        if(n==1) return costs[0];

        int i=0,j=n-1;
        priority_queue<p,vector<p>,greater<p>>pq;

        while(i<candidates && i<j){
             pq.push({costs[i],i});
             i++;
        }
        i--;
        while(j>=(n-candidates) && j>i){
             pq.push({costs[j],j});
             j--;
        } 
        j++;
        long long ans=0;

        while(k>0 && !pq.empty()){
          auto p=pq.top();
          pq.pop();

          int val=p.first;
          int idx=p.second;

          ans+=val;
          k--;

          if(idx<=i){
            i++;
            if(i<j) pq.push({costs[i],i});
          }
          if(idx>=j){
            j--;
            if(i<j) pq.push({costs[j],j});
          }
        //   cout<<ans<<" "<<i<<" "<<j<<endl;
        }
        return ans;
    }
};