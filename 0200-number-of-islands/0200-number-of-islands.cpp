class Solution {
public:
 void dfs(unordered_map<int,vector<int>>&mp,unordered_set<int>&st,int start){
          st.insert(start);

          for(auto neigh : mp[start]){
             if(!st.count(neigh)){
                dfs(mp,st,neigh);
             }
          }
   }
   
    int numIslands(vector<vector<char>>& grid) {
         unordered_map<int,vector<int>>mp;
        int node=grid.size();
        if(node==1 && grid[0][0]=='0') return 0;
        for(int i=0;i<node;i++){
            for(int j=0;j<node;j++){
                if(grid[i][j]=='1' && i!=j){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
          unordered_set<int>st;
        int ans=0;
       
        for(int i=0;i<node;i++){
            if(!st.count(i)){
             int start=i;
            dfs(mp,st,start);
            ans++;
            }
        }
        return ans;
    }
};