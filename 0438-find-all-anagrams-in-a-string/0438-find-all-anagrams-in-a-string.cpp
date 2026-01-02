class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp;
        int n=s.length();
        int m=p.length();

        for(auto &it : p) mp[it]++;
        int req=mp.size();

        unordered_map<char,int>map;

        int i=0,j=0;
        vector<int>ans;
        int cnt=0; 

        while(j<n){
            map[s[j]]++;
            if(mp.find(s[j])!=mp.end()){
                if(map[s[j]]==mp[s[j]]) cnt++;
            }

            if(j-i+1==m){
                if(cnt==req) ans.push_back(i);
                // if(map[s[i]]==mp[s[i]]) cnt--;
                if (mp.count(s[i]) && map[s[i]] == mp[s[i]])
                    cnt--;
                    map[s[i]]--;
                // if(map[s[i]]<mp[s[i]])
                i++;
            }

            j++;
        }
        return ans;
    }
};