class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n=emails.size();
        unordered_set<string>st;

        for(auto &it : emails){
            bool flag=false;
            string s="";
            bool bg=false;
            for(auto &x : it){
                if(!flag && !bg && x=='.') continue;
                else if(!flag && !bg && x=='+'){
                    flag=!flag;
                    continue;
                }
                else if(x=='@') {
                    // flag=!flag;
                    s.push_back(x);
                     bg=!bg;
                }
                else if(!flag || bg) s.push_back(x);
            }
            st.insert(s);
            cout<<s<<endl;
        }

        return st.size();
    }
};