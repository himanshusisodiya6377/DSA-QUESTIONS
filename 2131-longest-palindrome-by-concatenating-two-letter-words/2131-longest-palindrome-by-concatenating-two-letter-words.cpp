class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            mp[words[i]]++;
        }
        int count = 1;
        for (int i = 0; i < n; i++) {
            if (mp.find(words[i]) != mp.end()) {
                string fir = words[i];
                int freq1 = mp[words[i]];
                string rev = fir;
                reverse(rev.begin(), rev.end());
                if (mp.find(rev) != mp.end() && fir != rev) {
                    int freq2 = mp[rev];
                    if (freq1 > freq2) {
                        ans += freq2 * 4;
                        mp[fir] -= freq2;
                        mp.erase(rev);
                    } else if (freq1 < freq2) {
                        ans += freq1 * 4;
                        mp[rev] -= freq1;
                        mp.erase(fir);
                    } else {
                        ans += freq1 * 4;
                        mp.erase(fir);
                        mp.erase(rev);
                    }
                } else if (fir == rev) {
                    int freq=mp[fir]/2;
                    if(count==1 && freq==0){
                    ans += 2;
                    mp.erase(fir);
                    count--;
                    }
                    else if(freq>0){
                        ans+=4*freq;
                        mp[fir]-=2*freq;
                        if(mp[fir]==0) mp.erase(fir);
                    }
                } else
                    mp.erase(fir);
            }
        }
        return ans;
    }
};