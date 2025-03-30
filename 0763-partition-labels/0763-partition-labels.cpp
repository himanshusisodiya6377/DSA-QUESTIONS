class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> ans;
        vector<vector<int>> v(26, vector<int>(2, -1));
        for (int i = 0; i < n; i++) {
            if (v[s[i] - 'a'][0] == -1)
                v[s[i] - 'a'][0] = v[s[i] - 'a'][1] = i;
            else
                v[s[i] - 'a'][1] = i;
        }
        int end = -1;
        int inti = 0;
        int get = 0;
        for (int i = 0; i < n; i++) {
            if (end == -1) {
                end = v[s[i] - 'a'][1];
                get += (end - inti + 1);
                inti = v[s[i]-'a'][0];
            } else {
                int checkend = v[s[i]-'a'][1];
                int checkinti = v[s[i]-'a'][0];
                if (checkinti >= inti && checkend <= end)
                    continue;
                else if (checkinti >= inti && checkinti <= end &&
                         checkend > end) {
                    get += (checkend - end);
                    end = checkend;
                } else {
                    ans.push_back(get);
                    get = 0;
                    inti = v[s[i]-'a'][0];
                    end = v[s[i]-'a'][1];
                    get += (end - inti + 1);
                }
            }
        }
        ans.push_back(get);
        return ans;
    }
};