class Solution {
public:
    int n;
    vector<string>ans;
    unordered_set<string>st;
    unordered_set<string>mp;
    void solve(string &s,int idx,string t){
        if(idx>=n){
            // cout<<"yes";
            if(t.length()>0) mp.insert(t);
            return;
        }

        for(int i=1;i<=n;i++){
            // cout<<"yes"<<endl;
            string temp=s.substr(idx,i);
            // cout<<temp<<endl;
            if(st.find(temp)!=st.end()){
                t+=" "+temp;
                // cout<<t<<endl;
                solve(s,idx+i,t);
                t.resize(t.size()-(temp.size()+1));
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& word) {
        n=s.length();
        for(auto &it : word) st.insert(it);
        solve(s,0,"");
        for(auto &it : mp){
            ans.push_back(it.substr(1,it.length()-1));
        }
        return ans;
    }
};