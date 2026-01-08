class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        int n = s.size();
        if (k == 0) return true;

        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }

        vector<pair<int,int>> intervals;

        for (int i = 0; i < n; i++) {
            if (i != first[s[i] - 'a']) continue;

            int r = last[s[i] - 'a'];
            bool valid = true;

            for (int j = i; j <= r; j++) {
                int c = s[j] - 'a';
                if (first[c] < i) {
                    valid = false;
                    break;
                }
                r = max(r, last[c]);
            }

         
            if (valid && !(i == 0 && r == n - 1)) {
                intervals.push_back({i, r});
            }
        }

   
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        int cnt = 0;
        int last_end = -1;

        for (auto &in : intervals) {
            if (in.first > last_end) {
                cnt++;
                last_end = in.second;
            }
        }

        return cnt >= k;
    }
};
