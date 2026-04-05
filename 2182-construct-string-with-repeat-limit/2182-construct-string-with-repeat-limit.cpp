class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c - 'a']++;

        string ans = "";

        int i = 25;
        while(i >= 0) {
            if(freq[i] == 0) {
                i--;
                continue;
            }

            int use = min(freq[i], limit);

            // use current largest char
            for(int k = 0; k < use; k++)
                ans.push_back('a' + i);

            freq[i] -= use;

            // if still remaining, need breaker
            if(freq[i] > 0) {
                int j = i - 1;
                while(j >= 0 && freq[j] == 0) j--;

                if(j < 0) break; // no smaller char → STOP

                ans.push_back('a' + j);
                freq[j]--;
            }
        }

        return ans;
    }
};