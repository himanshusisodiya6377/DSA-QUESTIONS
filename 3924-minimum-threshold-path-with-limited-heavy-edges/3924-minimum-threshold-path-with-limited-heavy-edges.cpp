class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>adj;
    vector<bool>visit;
    vector<vector<int>> dp;
    bool dfs(int node,int target, int k,int mid,int count){
        
        if(node==target && count<=k) return true;
        if(node==target || count>k) return false;

        if(dp[node][count]!=-1) return dp[node][count];
        // if(mask & (1<<node)) return false;
    //    cout<<"yes"<<endl;
        for(auto &it : adj[node]){
            int nd=it.first;
            if(visit[nd]) continue;
            int wt=it.second;
            int new_cnt=count+ (wt>mid  ? 1 : 0);
            // mask=(mask | (1<<nd)); 
            visit[nd]=true;
            if(dfs(nd,target,k,mid,new_cnt)) return dp[node][count]=true;
            visit[nd]=false;
        }

        return dp[node][count]=false;
        
    }
    
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {

        for(auto &it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        visit.resize(n,false);
        int lo=0,hi=1e9;
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            visit.assign(n,false);
            visit[source]=true;
            dp.assign(n,vector<int>(k+1,-1));

            if(dfs(source,target,k,mid,0)){
               ans=mid;
               hi=mid-1;
            }
            else lo=mid+1;
            // cout<<mid<<endl;
        }

        return ans==INT_MAX ? -1 : ans;
    }
};