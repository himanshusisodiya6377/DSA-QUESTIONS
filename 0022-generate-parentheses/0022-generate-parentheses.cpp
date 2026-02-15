class Solution {
public:
    vector<string>ans;
    bool check(string &s){
        stack<char>st;
        for(auto &it : s){
            if(it=='(') st.push(it);
            else if(!st.empty() && st.top()=='(') st.pop();
            else return false;
        }

        return st.empty();
    }
    void solve(int n,int idx,string s,int open,int close){
        if(idx>=n-1){
            if(open==close) ans.push_back(s);
            // cout<<s<<endl;
            return;
        }
        s+="(";
        solve(n,idx+1,s,open+1,close);
        s.pop_back();
        
        if(open<=close) return;
        s+=")";
        solve(n,idx+1,s,open,close+1);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        solve(2*n,0,"(",1,0);
        return ans;
    }
};