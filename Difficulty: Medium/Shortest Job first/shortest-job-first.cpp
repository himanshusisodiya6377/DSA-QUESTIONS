// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it : bt) pq.push(it);
        
        long long ans=0;
        long long x=0;
        
        while(!pq.empty()){
            long long val=pq.top();
            pq.pop();
            x+=val;
            ans+=(x-val);
        }
        return ans/n;
    }
};