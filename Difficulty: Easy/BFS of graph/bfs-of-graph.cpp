//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    unordered_set<int>st;

    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        vector<int>ans;
        int r=adj.size();
            queue<int>qu;
    qu.push(0);
    st.insert(0);
          while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            ans.push_back(node);

            // Traverse all neighbors
            for (int neighbor : adj[node]) {
                if (st.find(neighbor) == st.end()) {  // If not visited
                    qu.push(neighbor);
                    st.insert(neighbor);
                }
            }
          }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends