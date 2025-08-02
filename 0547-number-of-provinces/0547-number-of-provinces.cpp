class Solution {
public:
void dfs(int node,vector<int>&visit,vector<vector<int>>&adj){
     
     visit[node]=1;

     for(auto it : adj[node]){
      if(visit[it]==0){
        dfs(it,visit,adj);
      }
     }

   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

          int cnt=0;
          vector<int>visit(n,0);
          for(int i=0;i<n;i++){
         
           if(visit[i]==0){
            cnt++;
            dfs(i,visit,adj);
         }
       }

       return cnt;
    }
};