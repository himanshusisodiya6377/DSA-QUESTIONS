class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n,INT_MAX);
        time[k-1]=0;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : times){
            int v=it[1];
            int wt=it[2];
            adj[it[0]-1].push_back({wt,v-1});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k-1});
        while(!q.empty()){
            int node=q.top().second;
            int weight=q.top().first;
            q.pop();
            for(auto it : adj[node]){
                if(time[it.second]>(time[node]+it.first)){
                    time[it.second]=time[node]+it.first;
                    q.push({time[it.second],it.second});
                }
            }
        }

        int mini=INT_MIN;
        for(int i=0;i<n;i++){
            if(time[i]==INT_MAX) return -1;
            mini=max(mini,time[i]);
        }
        return mini;
    }
};