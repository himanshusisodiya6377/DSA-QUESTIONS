class Solution {
public:
 int find( int a,vector<int>&parent){
         if(parent[a]==a) return a;
         return parent[a]=find(parent[a],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
         vector<int>parent(n,0);
        int m=edges.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>rank(n,1);
        for(int i=0;i<m;i++){
            int a=find(edges[i][0]-1,parent);
            int b=find(edges[i][1]-1,parent);
            if(a==b){
                ans.push_back({edges[i][0],edges[i][1]});
                continue;
            }
            if(rank[a]>=rank[b]){
                rank[a]++;
                parent[b]=a;
            }
            else{
                rank[b]++;
                parent[a]=b;
            }
        }
        // int par=parent[0];
        // for(int i=0;i<n;i++){
        //    if(parent[i]!=par) return false;
        // }
        return ans[ans.size()-1];
    }
    
};