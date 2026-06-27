class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       unordered_map<int,vector<int>>adj;
       if(n==1) return {0};
       
       vector<int>degree(n,0);
       for(auto &it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);

        degree[it[0]]++;
        degree[it[1]]++;
       }

       queue<int>q;
       vector<bool>visit(n,false);
       for(int i=0;i<n;i++){
        if(degree[i]==1) {
            q.push(i);
            visit[i]=true;
        }
       }
        vector<int>ans;
       while(!q.empty()){
        int sz=q.size();
        vector<int>temp;
        while(sz--){
           auto p=q.front();
           q.pop();

           temp.push_back(p);
           for(auto &it : adj[p]){
            degree[it]--;
            if(!visit[it] && degree[it]==1){
                q.push(it);
                visit[it]=true;
            }
           }
        }

        ans=temp;
       }
        return ans;
    }
};