class Solution {
public:
    bool parseBoolExpr(string exp) {
        int n=exp.length();
        int i=n-1;

        stack<char>st;

        while(i>=0){
            if(exp[i]=='f' || exp[i]=='t') st.push(exp[i]);
            else if(exp[i]==')') st.push(exp[i]);
            else if(exp[i]=='('){
                //we had a openinng char

                int ope=exp[i-1];
                if(ope=='!'){
                   char ch=st.top();
                   st.pop();
                   if(!st.empty()) st.pop();
                   (ch=='f' ? st.push('t') : st.push('f'));
                }
                else if(ope=='&'){
                    bool flag=true;
                   while(!st.empty() && st.top()!=')'){
                     char ch=st.top();
                     st.pop();
                     flag &= (ch=='f' ? false : true);
                   }
                   st.pop();
                   st.push(flag ? 't' : 'f');
                }
                else{
                   bool flag=false;
                   while(!st.empty() && st.top()!=')'){
                     char ch=st.top();
                     st.pop();
                     flag |= (ch=='f' ? false : true);
                   }
                   st.pop();
                   (flag==false ? st.push('f') : st.push('t'));
                }
            }
            i--;
        }

        return st.top()=='f' ? false : true;
    }
};