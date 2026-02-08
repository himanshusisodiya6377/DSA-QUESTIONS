class Solution {
public:
    typedef pair<long long,int> p; //weight node
    bool check(unordered_map<long long,vector<pair<long long,long long>>>&adj,long long k,long long n){
        //    if(adj.find(0)==adj.end() || adj.find(n-1)==adj.end()) return false;
           
           vector<long long>dist(n+1,LLONG_MAX);
           dist[0]=0;
           priority_queue<p,vector<p>,greater<p>>pq;
           pq.push({0,0});

           while(!pq.empty()){

            auto q=pq.top();
            pq.pop();

            long long wt=q.first;
            long long node=q.second;

            if(dist[node]<wt) continue;

            for(auto &it : adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
           }

           return (dist[n-1]==INT_MAX ? false : (dist[n-1]<=k ? true : false));
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        
        long long n=online.size();
        long long ans = -1;
        vector<long long>cost;
        // cost.push_back(0);

        for(auto &it : edges){
            cost.push_back(it[2]);
        }
        long long lo = 0, hi =cost.size()-1;

        sort(cost.begin(),cost.end());

        while (lo <= hi) {

            long long mid = lo + (hi - lo) / 2;

            // cout<<cost[mid]<<endl;
            
            unordered_map<long long,vector<pair<long long,long long>>>adj;

            for (auto& it : edges) {
                if (online[it[0]] && online[it[1]] && it[2] >= cost[mid]) {
                    adj[it[0]].push_back({it[1],it[2]});
                }
            }

            if (check(adj,k,n)) {
                ans = cost[mid];
                lo = mid + 1;
            } else
                hi = mid - 1;
        }

        return ans;
    }
};