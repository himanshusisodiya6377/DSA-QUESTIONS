class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        int n = path.length();
        stack<string> st;
        string check = "";
        for (int i =0; i <n; i++) {
            if (path[i] != '/') {
                check.push_back(path[i]);
            } 
            else{
                if(check==".") check="";
                else if(check==".."){
                    if(st.size()!=0) st.pop();
                    check="";
                }
                else{
                    if(check!="") st.push(check);
                    check="";
                }
            }
            // cout<<check<<endl;
        }
        if(check==".."){
            if(st.size()!=0) st.pop();
        }
        else if(check!="." && check!="") st.push(check);
        stack<string> rev;
        while (st.size() != 0) {
            string tope = st.top();
            rev.push(tope);
            st.pop();
        }
        
        while (rev.size() != 0) {
            string tope = rev.top();
            ans.push_back('/');
            ans += tope;
            rev.pop();
        }
        if(ans.size()==0) ans+="/";
        return ans;
    }
};