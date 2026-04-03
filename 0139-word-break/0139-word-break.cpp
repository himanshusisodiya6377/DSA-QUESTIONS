class Solution {
public:
    unordered_set<string>st;
    map<pair<int,string>,bool>mp;
    bool solve(string &s,int idx,string t){
        if(idx>=s.length()){
            // cout<<t<<endl;
            if(st.find(t)==st.end()) return false;
            return true;
        }

        if(mp.find({idx,t})!=mp.end()) return mp[{idx,t}];
        
        t.push_back(s[idx]);
        bool inc=solve(s,idx+1,t);
        if(inc) return   mp[{idx,t}]=true;
        t.pop_back();
        
        int not_inc=false;
        if(st.find(t)!=st.end()){
            string a="";
            a.push_back(s[idx]);
            not_inc=solve(s,idx+1,a);
            if(not_inc) return   mp[{idx,t}]=true;
        }

        return   mp[{idx,t}]=inc || not_inc;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
         for(auto &it : wordDict) st.insert(it);
         return solve(s,0,"");
    }
};