//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> khan(vector<vector<int>>&edges,int v){
        vector<int>ans;
        vector<int>indegree(v,0);
        for(auto edge : edges){
            indegree[edge[1]]++;
        }
        vector<vector<int>> adj(v);
    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        }
        queue<int>q;
        // unordered_set<int>visit;
        for(int i=0;i<v;i++){
            if(indegree[i]==0) {
                q.push(i);
                // visit.insert(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            ans.push_back(x);
            q.pop();
               for(int neigh : adj[x]){
                   indegree[neigh]--;
                   if(indegree[neigh]==0){
                       q.push(neigh);
                   }
               }
        }
        return ans;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>flag=khan(edges,V);
        return flag;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends