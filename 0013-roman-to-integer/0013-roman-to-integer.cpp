class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> mp;
        mp["M"] = 1000;
        mp["CM"] = 900;
        mp["D"] = 500;
        mp["CD"] = 400;
        mp["C"] = 100;
        mp["XC"] = 90;
        mp["L"] = 50;
        mp["XL"] = 40;
        mp["X"] = 10;
        mp["IX"] = 9;
        mp["V"] = 5;
        mp["IV"] = 4;
        mp["I"] = 1;
        int n = 0;
        for (int i = 0; i < s.length(); i++) {
            string ch = "";
            if (i != s.length()) {
                ch.push_back(s[i]);
                ch.push_back(s[i + 1]);
                if (mp.find(ch) != mp.end()) {
                    n += mp[ch];
                    i++;
                } else {
                    ch.pop_back();
                    n += mp[ch];
                }
            } else {
                ch.push_back(s[i]);
                n += mp[ch];
            }
        }
        return n;
    }
};