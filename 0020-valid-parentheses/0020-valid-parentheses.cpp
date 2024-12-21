class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        char ch;
        for(int i=0;i<s.length();i++){
            if(st.size()!=0) ch=st.top();
            if(s[i]=='(') st.push('(');
            else if(s[i]=='{') st.push('{');
            else if(s[i]=='[') st.push('[');
            else if(ch=='(' && s[i]==')'){
            st.pop();
            ch=' ';
            } 
            else if(ch=='{' && s[i]=='}'){
                 st.pop();
                  ch=' ';
            } 
            else if(ch=='[' && s[i]==']') {
            st.pop();
            ch=' ';
            }
            else return false;
        }
        if(st.size()==0) return true;
        else return false;
    }
};