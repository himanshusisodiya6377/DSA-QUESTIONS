class Solution {
public:
  bool isvowel(char& ch){
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                return true;
            return false;
        }
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_map<char, int> mp;
      
        int cont = 0;
        long long count = 0;
        int i = 0;
        int j = 0;
        vector<int> nextcont(n);
        int lastconstidx = n;
        for (int i = n - 1; i >= 0; i--) {
            nextcont[i] = lastconstidx;
            if (!isvowel(word[i])) {
                lastconstidx = i;
            }
        }
        while (j < n) {
            if (isvowel(word[j])) {
                mp[word[j]]++;
            } else{
             cont++;
            }
                
            while (cont > k) {
                char ch = word[i];
                if (isvowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0)
                        mp.erase(ch);
                } else{
                    cont--;
                }
                    
                i++;
            }
            while (i < n && mp.size() == 5 && cont == k) {
                int idx = nextcont[j];
                count += (idx - j);
                char ch = word[i];
                if (isvowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0)
                        mp.erase(ch);
                } else
                    cont--;
                i++;
            }
            j++;
        }
        return count;
    }
};