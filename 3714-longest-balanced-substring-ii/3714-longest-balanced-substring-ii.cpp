class Solution {
public:

    int getLongestSubstring(char a, char b, char c, string &s){
        int n = s.size();
        int i = 0;
        int res = 0;
        while(i < n){
            if(s[i] == c){
                i++;
                continue;
            }
            int j = i;
            int sum = 0;
            unordered_map<int, int>mp;
            mp[sum] = j-1;

            while(j < n && s[j] != c){
                sum += (a == s[j] ? 1 : -1);
                if(!mp.count(sum)) mp[sum] = j;
                else res = max(res, j - mp[sum]);
                j++;
            }
            i = j;
        }
        return res;

    }
    int longestBalanced(string s) {
        int n = s.size();

        int ans = 1, c = 1;

        // Type - 1
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]){
                c++;
            } else c = 1;
            ans = max(ans, c);
        }

        // Type - 2
        ans = max(ans, getLongestSubstring('a', 'b', 'c', s));
        ans = max(ans, getLongestSubstring('a', 'c', 'b', s));
        ans = max(ans, getLongestSubstring('b', 'c', 'a', s));

        // Type - 3

        int a = 0, b = 0;
        c = 0;
        map<pair<int, int>, int>mp;
        mp[{0, 0}] = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else c++;

            pair<int, int>p = {a - b, a - c};
            if(mp.count(p)) ans = max(ans, i - mp[p]);
            else mp[p] = i;
        }
        return ans;
    }
};