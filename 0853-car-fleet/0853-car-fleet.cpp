class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& sp) {
        vector<pair<int, int>> v;
        int n = pos.size();
        for (int i = 0; i < n; i++) {
            v.push_back({pos[i], sp[i]});
        }
        sort(v.rbegin(), v.rend());
        stack<double> st;
        for (int i = 0; i < n; i++) {
            int p = v[i].first;
            int s = v[i].second;
            if (st.empty()) {
                int dis = tar - p;
                double div = ((double)dis / s);
                st.push(div);
            } else {
                if (p + s * (double)st.top() < tar) {
                    int dis = tar - p;
                    double div = ((double)dis / s);
                    st.push(div);
                }
            }
        }
        return st.size();
    }
};