class Solution {
public:
    vector<vector<int>>memo;
    bool check(int node,int tar,unordered_map<int,unordered_set<int>>&adj){
          
          bool flag=false;
          if(memo[node][tar]!=-1) return memo[node][tar];
          for(auto &it : adj[node]){
            if(it==tar) return memo[node][tar]=1;

            flag = flag | check(it,tar,adj);
            if(flag) return memo[node][tar]=1;
          }

          return memo[node][tar]=flag;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<bool>ans(q.size(),false);
        if(pre.size()==0) return ans;
        
        memo.resize(n+1,vector<int>(n+1,-1));
        unordered_map<int,unordered_set<int>>adj;
        vector<int>indegree(n,0);
        vector<bool>mark(n,false);

        for(auto &it : pre){
            adj[it[0]].insert(it[1]);
            indegree[it[1]]++;
            mark[it[0]]=true;
            mark[it[1]]=true;
        }
        
        //lets apply khans algo
        queue<int>que;

        vector<int>topo;

        for(int i=0;i<n;i++){
            if(indegree[i]==0 && mark[i]){
                que.push(i);
            }
        }

        while(!que.empty()){

            topo.push_back(que.front());

            for(auto &aj : adj[que.front()]){
                indegree[aj]--;
                if(indegree[aj]==0) que.push(aj);
            }

            que.pop();
        }

        // for(auto &it : topo) cout<<it<<" ";

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++) mp[topo[i]]=i;
        int i=0;
        for(auto &it : q){
            if(mp.find(it[0])!=mp.end() && mp.find(it[1])!=mp.end() && check(it[0],it[1],adj)){
                if(mp[it[0]]<mp[it[1]]) ans[i]=true;
            }
            i++;
        }

        return ans;
    }
};