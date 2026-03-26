class Solution {
public:
    int cnt;
    // string ans;
    bool check(string &ans,string &s){
        unordered_set<char>st;
        unordered_set<char>pt;
        for(auto &it : ans) st.insert(it);

        for(auto &it :s){
            if(st.count(it) || pt.count(it)) return false;
            pt.insert(it);
        }

        // st.clear();
        

        return true;
    }
    void solve(vector<string>&arr,int idx,string ans){
        if(idx>=arr.size()){
         cnt=max(cnt,(int)ans.length());
        //    cout<<ans<<" "<<cnt<<endl;
           return;
        }

        bool flag=false;

        if(check(ans,arr[idx])){
        flag=true; 
        ans+=arr[idx];
        // cout<<ans<<endl;
        solve(arr,idx+1,ans);
        }
        //  cout<<ans<<endl;
        if(flag) ans=ans.substr(0,ans.length()-arr[idx].length());
        // cout<<ans<<endl;
        solve(arr,idx+1,ans);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        cnt=0;
        string ans="";
        solve(arr,0,ans);
        return cnt;
    }
};