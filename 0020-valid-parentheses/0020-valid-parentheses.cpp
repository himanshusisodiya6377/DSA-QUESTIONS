class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        //T.C=O(n);
        char ch;
        for(int i=0;i<s.length();i++){
            //iterating every element of string
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            //get ch than compare for pop 
            else if(st.size()>0 && st.top()=='(' && s[i]==')'){
            st.pop();
            //important to enpty other wise runtime it will try to access empty stack
            //when stack is going to empty but any if else condition
            //going to compare with previous old ch so thats why need to empty it
            } 
            else if(st.size()>0 && st.top()=='{' && s[i]=='}'){
                 st.pop();
            } 
            else if(st.size()>0 && st.top()=='[' && s[i]==']') {
            st.pop();
            }
            else return false;
        }
        if(st.size()==0) return true;
        else return false;
    }
};