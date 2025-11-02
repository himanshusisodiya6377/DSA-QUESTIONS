class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,unordered_set<int>>mp;
        unordered_map<int,vector<int>>adj;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        for(auto it : edges){
            mp[it[1]].insert(it[0]);
        }
        vector<int>indegree(V,0);
        for(auto it : mp){
            indegree[it.first]=it.second.size();
            // cout<<it.first<<" ";
            // cout<<endl;
            // for(auto x : it.second) cout<<x<<" ";
            // cout<<endl;
        }
        // cout<<endl;
        
        // for(auto it : indegree) cout<<it<<" ";
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>temp;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            temp.push_back(x);
            for(auto it : adj[x]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        // for(auto it : temp) cout<<it<<" ";
        int ans=0;
        for(int i=0;i<temp.size();i++){
            for(int j=i+1;j<temp.size();j++){
                if(mp[j].find(i)==mp[j].end() && mp[i].find(j)==mp[i].end()){
                    ans++;
                }
            }
        }
       return ans;
    }
};
