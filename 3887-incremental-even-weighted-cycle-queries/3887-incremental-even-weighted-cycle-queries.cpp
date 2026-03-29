class Solution {
public:
    vector<int> parent, parity;

    int find(int x) {
        if (parent[x] == x) return x;

        int p = parent[x];
        parent[x] = find(parent[x]);
        parity[x] ^= parity[p];

        return parent[x];
    }

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        parity.assign(n, 0);

        for (int i = 0; i < n; i++) parent[i] = i;

        int count = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            int pu = find(u), pv = find(v);

            if (pu == pv) {
                if ((parity[u] ^ parity[v]) == w)
                    count++;
            } else {
                parent[pu] = pv;
                parity[pu] = parity[u] ^ parity[v] ^ w;
                count++;
            }
        }

        return count;
    }
};