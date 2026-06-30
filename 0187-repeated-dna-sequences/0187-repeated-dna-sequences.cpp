class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        
        if(n<=9) return {};
        unordered_map<string,int>mp;
        unordered_set<string>st;

        int i=0,j=9;
        
        while(j<n){
            string t=s.substr(i,j-i+1);

            mp[t]++;
            if(mp[t]>1) st.insert(t);
            i++;
            j++;
        }

        vector<string>ans;
        for(auto &it : st) ans.push_back(it);
        return ans;

    }
};