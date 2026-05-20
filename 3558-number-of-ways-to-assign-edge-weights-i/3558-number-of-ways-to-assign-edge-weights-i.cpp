class Solution {
public:
    int mod=1e9+7;
    int get_depth(int n, unordered_map<int,vector<int>>&adj){

        vector<bool>visit(n+2,false);
        queue<int>q;

        q.push(1);
        visit[1]=true;
        int depth=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            auto p=q.front();
            q.pop();

            for(auto &it : adj[p]){
                if(!visit[it]){
                    visit[it]=true;
                    q.push(it);
                }
            }
            }
            if(q.empty()) return depth;
            depth++;
        }
        return depth;
    }
    long long modpow(long long a, long long b, long long mod) {

    long long ans = 1;

    while (b > 0) {

        if (b & 1)
            ans = (ans * a) % mod;

        a = (a * a) % mod;

        b >>= 1;
    }

    return ans;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>>adj;

        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int depth=get_depth(n,adj);
        // cout<<depth<<endl;
        long long ans=0;

        ans+=modpow(2,depth-1,mod);
        ans=ans%mod;
        return ans;
    }
};