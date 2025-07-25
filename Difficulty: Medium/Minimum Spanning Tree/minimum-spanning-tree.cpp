class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<int>visit(V,0);
        //holding {node,weight} parent se reach karne me is node ko kitna weight lga 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        int ans=0;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            pair<int,int>it=pq.top();
            pq.pop();
            
            if(visit[it.second]==1) continue;
            
            visit[it.second]=1;
            ans+=it.first;
            
            for(auto v : adj[it.second]){
                if(visit[v[0]]==1) continue;
                
                pq.push({v[1],v[0]});
                
            }
        }
        
        return ans;
        
    }
};