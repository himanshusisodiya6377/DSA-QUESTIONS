class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(auto p : mp){
            int m=(p.second);
            if(m%2==0) ans+=2;
            else ans+=1;
        }
        return ans;
    }
};