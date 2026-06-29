class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x]==x) return parent[x];
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int par_x=find(x);
        int par_y=find(y);

        if(par_x==par_y) return;

        if(rank[par_x]<rank[par_y]){
            parent[par_x]=par_y;
        }
        else if(rank[par_y]<rank[par_x]){
            parent[par_y]=par_x;
        }
        else{
            parent[par_y]=par_x;
            rank[par_y]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        rank.resize(n,0);
        parent.resize(n,0);

        for(int i=0;i<n;i++) parent[i]=i;

        unordered_map<string,vector<int>>mp;

        for(auto i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                mp[accounts[i][j]].push_back(i);
            }
        }

        for(auto &it : mp){
            for(int i=0;i<it.second.size()-1;i++){
                Union(it.second[i],it.second[i+1]);
            }
        }

        vector<set<string>>ans(n);

        for(int i=0;i<accounts.size();i++){
            int par=find(i);
            // cout<<par<<endl;
            for(int j=1;j<accounts[i].size();j++){
                ans[find(par)].insert(accounts[i][j]);
            }
        }

        vector<vector<string>>res;
        
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()==0) continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto &it : ans[i]) temp.push_back(it);
            res.push_back(temp);
        }

        return res;
    }
};