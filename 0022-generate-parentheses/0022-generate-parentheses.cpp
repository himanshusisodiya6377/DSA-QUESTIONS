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
    void solve(int n,int idx,string s){
        if(idx>=n-1){
            if(check(s)) ans.push_back(s);
            cout<<s<<endl;
            return;
        }
        s+="(";
        solve(n,idx+1,s);
        s.pop_back();

        s+=")";
        solve(n,idx+1,s);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        solve(2*n,0,"(");
        return ans;
    }
};