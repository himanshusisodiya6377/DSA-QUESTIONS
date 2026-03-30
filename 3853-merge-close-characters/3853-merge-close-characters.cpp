class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n=s.length();
        unordered_map<char,int>mp;

        string ans="";
        // for(int i=0;i<n;i++){
        //     if(mp.find(s[i])!=mp.end() && i-mp[s[i]]<=k){
        //         continue;
        //     }
        //     else {
        //         if(mp.find(s[i])==mp.end()) mp[s[i]]=i;
        //         ans.push_back(s[i]);
        //     }
        // }
        stack<char>st;
        int idx=0;
        for(auto &it : s){
            if(mp.find(it)==mp.end()){
                st.push(it);
                mp[it]=idx;
                idx++;
            }
            else{
                if(idx-mp[it]<=k){
                    continue;
                }
                else{
                    st.push(it);
                    mp[it]=idx;
                    idx++;
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};