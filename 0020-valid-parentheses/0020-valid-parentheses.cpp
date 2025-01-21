class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        //T.C=O(n);
        char ch;
        for(int i=0;i<s.length();i++){
            //iterating every element of string
            if(st.size()!=0) ch=st.top();
            if(s[i]=='(') st.push('(');
            else if(s[i]=='{') st.push('{');
            else if(s[i]=='[') st.push('[');
            //get ch than compare for pop 
            else if(ch=='(' && s[i]==')'){
            st.pop();
            //important to enpty other wise runtime it will try to access empty stack
            ch=' ';//when stack is going to empty but any if else condition
            //going to compare with previous old ch so thats why need to empty it
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