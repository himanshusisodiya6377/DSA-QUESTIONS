class Solution {
public:
        long long feul=0;
    long long dfs(unordered_map<int,vector<int>>&adj,int node,int seats,int parent){
        long long people = 1;
        for(auto &it : adj[node]){
            if(it!=parent){
                people+=dfs(adj,it,seats,node);
                // cout<<node<<" "<<p.first<<" "<<p.second<<endl;
            }
        }
        // cout<<node<<" "<<cars<<" "<<seat<<endl;
        if(node==0) return people;
        feul+=(people+(seats-1))/seats;
        // feul+=cars;
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans=0;
        unordered_map<int,vector<int>>adj;
        // int n=roads.size();
        // cout<<n<<endl;
        // vector<int>degree(n+1,0);

        for(auto &it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            // degree[it[0]]++;
            // degree[it[1]]++;
        }
        dfs(adj,0,seats,-1);
        // for(auto &it : degree) cout<<it<<" ";
        return feul;
    }
};