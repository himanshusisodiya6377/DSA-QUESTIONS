class Solution {
public:
    string customSortString(string order, string s) {
        // unordered_map<char, int> mp;
        vector<int>v(26,0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            v[s[i]-'a']++;
        }
        string ans = "";
        for (int i = 0; i < order.length(); i++) {
            if (v[order[i]-'a'] != 0) {
                int freq = v[order[i]-'a'];
                while (freq > 0) {
                    ans.push_back(order[i]);
                    freq--;
                }
                v[order[i]-'a']=0;
            }
        }
        for (int i=0;i<26;i++) {
            int freq = v[i];
            char ch=i+'a';
            while (freq > 0) {
                ans.push_back(ch);
                freq--;
            }
        }
        return ans;
    }
};