class Solution {
public:
     #define ppr pair<int, int>
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,vector<pair<int,int>>>adj;
        
        vector<bool>visit(n,false);
        int time=0;
        for(auto &it : meetings){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            // if(it[0]==0 && it[1]==firstPerson || it[1]==0 && it[0]==firstPerson) time=it[2];
        }

        vector<int>ans;
        // ans.push_back(0);
        // ans.push_back(firstPerson);

        // visit[0]=true;
        priority_queue<ppr, vector<ppr>, greater<ppr> > q;
        q.push({0, 0});
        q.push({0, firstPerson});
        // visit[firstPerson]=true;

        while(!q.empty()){
            auto p=q.top();
            q.pop();
            //  cout<<"yes";
            int node=p.second;
            int tm=p.first;

            if(visit[node])
    continue;

            ans.push_back(node);
            visit[node]=true;
            for(auto &it : adj[node]){
                if(!visit[it.first] && it.second>=tm){
                   q.push({it.second,it.first});
                }
            }
        }
        return ans;
    }
};