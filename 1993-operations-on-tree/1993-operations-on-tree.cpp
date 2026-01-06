class LockingTree {
public:
    unordered_map<int,int> mp;   // node -> user, -1 = unlocked
    unordered_map<int,int> adj;  // parent
    unordered_map<int,vector<int>> adj_rev; // children

    LockingTree(vector<int>& parent) {
        int n = parent.size();
        for(int i = 0; i < n; i++){
            mp[i] = -1;
            adj[i] = parent[i];
            if(parent[i] != -1)
                adj_rev[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if(mp[num] != -1) return false;
        mp[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if(mp[num] == -1 || mp[num] != user) return false;
        mp[num] = -1;
        return true;
    }

    // ✅ FIXED: return true ONLY if some ancestor is locked
    bool dfs_rev(int num){
        while(adj[num] != -1){
            num = adj[num];
            if(mp[num] != -1) return true;
        }
        return false;
    }

    // ✅ FIXED: check if there exists at least one locked descendant
    bool unlock_dec(int num){
        for(auto &it : adj_rev[num]){
            if(mp[it] != -1) return true;
            if(unlock_dec(it)) return true;
        }
        return false;
    }

    // ✅ unchanged logic, just unlock descendants
    void dfs(int num){
        for(auto &it : adj_rev[num]){
            dfs(it);
        }
        mp[num] = -1;
    }

    bool upgrade(int num, int user) {
        if(mp[num] != -1) return false;      // condition 1
        if(dfs_rev(num)) return false;       // condition 3
        if(!unlock_dec(num)) return false;   // condition 2

        dfs(num);                            // unlock all descendants
        mp[num] = user;                     // lock current node
        return true;
    }
};
