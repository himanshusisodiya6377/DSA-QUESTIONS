class Solution {
public:
    int dfs(vector<bool>&Apple,int node,unordered_map<int,vector<int>>&adj,vector<int>&visit){
        if(visit[node]) return 0;
        visit[node]=true;
        bool itself=false;
        int tmp=0;
        if(Apple[node]) itself=true;
        for(auto &it : adj[node]){
            if(!visit[it])
            tmp+=dfs(Apple,it,adj,visit);
        }
        if((itself || tmp!=0) && node!=0 ) return 2+tmp;
        if((itself || tmp!=0) && node==0 ) return tmp;
        if(!itself && tmp==0) return 0;
        return -1;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int sz=edges.size();
        unordered_map<int,vector<int>>adj;
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }    
        vector<int>visit(n,false);
        return dfs(hasApple,0,adj,visit);
    }
};