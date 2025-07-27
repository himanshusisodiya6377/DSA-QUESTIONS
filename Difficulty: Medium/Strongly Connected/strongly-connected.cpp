//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int node,vector<int>&visit,stack<int>&st,vector<vector<int>>&adj){
        visit[node]=1;
        
        for(auto it : adj[node]){
            if(visit[it]==0){
                dfs(it,visit,st,adj);
            }
        }
        
        st.push(node);
    }
    
    void dfs2(int node,vector<int>&visit,vector<vector<int>>&adjT){
        visit[node]=1;
        
        for(auto it : adjT[node]){
            if(visit[it]==0){
                dfs2(it,visit,adjT);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int>visit(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                dfs(i,visit,st,adj);
            }
        }
        
        vector<vector<int>>adjT(n);
        for(int i=0;i<n;i++){
            visit[i]=0;
            for(auto it : adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int cnt=0;
       
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(visit[top]==0){
                dfs2(top,visit,adjT);
                cnt++;
            }
        }
        
        return cnt;
    }
};