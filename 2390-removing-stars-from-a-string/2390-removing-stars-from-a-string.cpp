class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string ans="";
        while(st.size()>0){
            char ch=st.top();
            ans.push_back(ch);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};