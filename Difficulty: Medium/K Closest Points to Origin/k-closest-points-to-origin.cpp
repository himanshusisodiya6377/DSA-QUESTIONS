class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        for (int i = 0; i < points.size(); i++) {
            long long dist = (1LL * points[i][0] * points[i][0]) + (1LL * points[i][1] * points[i][1]);
            pq.push({dist, i});
        }

    //   while(!pq.empty()){
    //       cout<<pq.top().first<<" "<<pq.top().second<<endl;
    //   }
       vector<vector<int>>ans;
       while(k--){
           ans.push_back(points[pq.top().second]);
           pq.pop();
       }
       return ans;
    }
};