class Solution {
public:
    class DSU {

    public:
        map<int, pair<int, int>> mp; // component parent --> even odd
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            rank.resize(n, 0);
            parent.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                mp[i] = {0, 0};
            }
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }

        void Union(int x, int y) {
            int par_x = find(x);
            int par_y = find(y);

            if (par_x == par_y)
                return;

            if (rank[par_x] < rank[par_y]) {
                parent[par_x] = par_y;
                mp[par_y].first += mp[par_x].first;
                mp[par_y].second += mp[par_x].second;
                mp.erase(par_x);
            } else if (rank[par_x] > rank[par_y]) {
                parent[par_y] = par_x;
                mp[par_x].first += mp[par_y].first;
                mp[par_x].second += mp[par_y].second;
                mp.erase(par_y);
            } else {
                parent[par_x] = par_y;
                rank[par_y]++;
                mp[par_y].first += mp[par_x].first;
                mp[par_y].second += mp[par_x].second;
                mp.erase(par_x);
            }
        }
    };
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        DSU ds(n);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                ds.mp[i].first++;
            else
                ds.mp[i].second++;
        }

        // created complete graph
        for (auto& it : swaps) {
            int x = it[0];
            int y = it[1];
            int par_x = ds.find(x);
            int par_y = ds.find(y);

            // if(x%2==0) ds.mp[par_x].first++;
            // else ds.mp[par_x].second++;

            // if(y%2==0) ds.mp[par_y].first++;
            // else ds.mp[par_y].second++;

            ds.Union(x, y);
        }

        long long sum = 0;
        vector<pair<int, int>> v; // value index
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});
        sort(v.begin(), v.end());

        for (int i = n - 1; i >= 0; i--) {
            int par_i = ds.find(v[i].second);
            if (ds.mp[par_i].first > 0) {
                sum += v[i].first;
                ds.mp[par_i].first--;
            } else {
                sum -= v[i].first;
                ds.mp[par_i].second--;
            }
        }

        for (auto& it : ds.mp) {
            cout << it.first << " " << it.second.first << " "
                 << it.second.second << endl;
        }

        return sum;
    }
};