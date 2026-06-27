class Solution {
public:
    int ans;
    long long sum;
    int dfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&values,vector<bool>&visit,int k){
        long long s=values[node];
        visit[node]=true;
        for(auto &it : adj[node]){
            if(!visit[it]){
                s+=dfs(it,adj,values,visit,k);
            }
        }
        // cout<<

        if((sum-s)%k==0){
            ans++;
            sum-=s;
            return 0;
        }

        return s;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>adj;
        ans=0;

        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        sum=0;
        
        for(int i=0;i<n;i++) {
            values[i]=values[i]%k;
            sum+=values[i];
        }

        vector<bool>visit(n,false);

        dfs(0,adj,values,visit,k);
        return ans==0 ? 1 : ans;
    }
};