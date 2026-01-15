class Solution {
public:
    typedef pair<int, int> p;
    int candy(vector<int>& rat) {
        int n = rat.size();
        vector<int> v(n, 1);
        // int cand=n;

        priority_queue<p, vector<p>, greater<p>> pq;

        for (int i = 0; i < n; i++)
            pq.push({rat[i], i});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int idx = p.second;

            int candy = 1;

            if (idx > 0 && rat[idx - 1] < rat[idx]) {
                candy = max(candy, v[idx - 1] + 1);
            }

            if (idx < n - 1 && rat[idx] > rat[idx + 1]) {
                candy = max(candy, v[idx + 1] + 1);
            }

            v[idx] = candy;
        }

        int cand = 0;
        for (auto& it : v) {
            cand += it;
        }
        return cand;
    }
};