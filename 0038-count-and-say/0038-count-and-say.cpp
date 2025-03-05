class Solution {
public:
    string calstring(string st, int n) {
        string ans = "";
        int i = 0, j = i + 1;
        int count = 1;
        while (j < n) {
            if (st[j] == st[i]) {
                count++;
                j++;
            } else {
                ans += to_string(count);
                ans += st[i];
                count = 1;
                i = j;
                j++;
            }
        }
        ans += to_string(count);
        ans += st[i];

        return ans;
    }
    string countAndSay(int n) {
        int m = 1;
        string ans = "1";
        while (m != n) {
            ans = calstring(ans, ans.length());
            m++;
        }
        return ans;
    }
};