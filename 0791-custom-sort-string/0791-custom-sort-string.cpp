class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        string ans="";
        for(int i=0;i<order.length();i++){
            if(mp.find(order[i])!=mp.end()){
                int freq=mp[order[i]];
                while(freq>0){
                    ans.push_back(order[i]);
                    freq--;
                }
                mp.erase(order[i]);
            }
        }
        for(auto p : mp){
            int freq=p.second;
            while(freq>0){
                ans.push_back(p.first);
                freq--;
            }
        }
        return ans;
    }
};