class Solution {
public:

    int find(int node,vector<int>&parent){
        if(node==parent[node]) return parent[node];
        return parent[node]=find(parent[node],parent);
    }

    void uniongp(int u,int v,vector<int>&parent,vector<int>&rank){

        int par_u=find(u,parent);
        int par_v=find(v,parent);

        if(par_u==par_v) return;

        if(rank[par_u]<rank[par_v]){
           parent[par_u]=par_v;
        }
        else if(rank[par_v]<rank[par_u]){
           parent[par_v]=par_u;
        }
        else{
           parent[par_u]=par_v;
           rank[par_u]++;
        }

        return;

    }

    int minCostConnectPoints(vector<vector<int>>& points) {
         
        int n=points.size();

        int ans=0;
        
        //declaration
        vector<int>rank(n,0);
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        vector<pair<int,pair<int,int>>>v;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                 v.push_back({wt,{i,j}});
            }
        }

        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++){
            auto p=v[i];
            pair<int,int>it=p.second;
            if(find(it.first,parent)==find(it.second,parent)) continue;

            uniongp(it.first,it.second,parent,rank);
            ans+=p.first;
        }

        return ans;

    }
};