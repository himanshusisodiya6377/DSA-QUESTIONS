class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false; // Cycle detected
        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        DSU dsu(n);

        // Step 1: No multiple parents
        for (int i = 0; i < n; i++) {
            for (int child : {leftChild[i], rightChild[i]}) {
                if (child == -1) continue;
                if (++indegree[child] > 1) return false; // Multiple parents ❌

                // Step 2: Check cycle using DSU
                if (!dsu.unite(i, child)) return false; // Cycle ❌
            }
        }

        // Step 3: Ensure exactly one connected component
        int rootCount = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) rootCount++;
        }

        return rootCount == 1; // Only one root allowed ✅
    }
};
