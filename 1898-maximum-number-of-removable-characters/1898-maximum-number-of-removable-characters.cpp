class Solution {
public:
    //look at the approach how we use the map to validate our mid (fabulous)
    bool check(string& s, string& p, vector<int>& rem, int mid,
               unordered_map<int, int>& mp) {
        int i = 0, j = 0;
        while (i < s.length() && j < p.length()) {
            if (mp.find(i) == mp.end()) {
                if (s[i] == p[j]) {
                    i++;
                    j++;
                } else
                    i++;
            } else {
                if (mp[i] <= mid - 1)
                    i++;
                else {
                    if (s[i] == p[j]) {
                        i++;
                        j++;
                    } else
                        i++;
                }
            }
        }
        return j >= p.length();
    }
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int n = rem.size();
        int lo = 1, hi = rem.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < rem.size(); i++)
            mp[rem[i]] = i;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(s, p, rem, mid, mp)) {
                ans = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        return ans;
    }
};