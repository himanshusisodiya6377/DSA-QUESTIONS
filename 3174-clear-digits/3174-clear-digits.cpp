class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] >= 48 && s[i] <= 57) {
                if (ans.size() != 0) {
                    ans.pop_back();
                }
            } else
                ans.push_back(s[i]);
        }
        return ans;
    }
};