class Solution {
public:
int solve(int val1,int val2,char ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}
    int evalRPN(vector<string>& tokens) {
    stack<int>st;//storing values
    for(int i=0;i<tokens.size();i++){
        // char ch=tokens[0][i];
        // int n=stoi(tokens[i][0]);
        if(tokens[i]=="/" || tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*"){
                int val2=st.top();
                //directly pop store nahi kr rha tha check with sir
                 st.pop();
                int val1=st.top();
                 st.pop(); 
               char ch=tokens[i][0];
                int ans=solve(val1,val2,ch);
                st.push(ans);
        }
        else{
           int n=stoi(tokens[i]);
            st.push(n);
        }
    }   
    return st.top();
    }
};