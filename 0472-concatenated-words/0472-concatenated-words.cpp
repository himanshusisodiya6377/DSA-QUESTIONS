class Solution {
public:
    set<string>st;
    vector<vector<int>>dp;
    bool check(string &s,int idx,int cnt){
        if(idx>=s.length()){
            return cnt>1 ? true : false;
        }

        if(dp[idx][cnt]!=-1) return dp[idx][cnt];
        // cout<<s<<"*"<<endl;

        for(int i=idx;i<s.length();i++){
            // cout<<s.substr(idx,i-idx+1)<<endl;
            if(st.count(s.substr(idx,i-idx+1)) && check(s,i+1,cnt+1)) return dp[idx][cnt]=true;
        }

        return dp[idx][cnt]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        
        for(auto &it : words) st.insert(it);

        for(auto &it : words){
            dp.assign(it.length(), vector<int>(30, -1));
            if(check(it,0,0)) ans.push_back(it);
        }

        return ans;
    }
};