class Solution {
public:
    int calculate(string s) {
        long long n=s.length();
        stack<int>st;
        int result=0;
        long long number=0;
        long long sign=1;//1--> + -1 ---> -
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                number=number*10+(s[i]-'0'); //number banate chalo
            }
            else if(s[i]=='+'){
                result+=(number*sign);
                sign=1;
                number=0;
            }
            else if(s[i]=='-'){
                result+=(number*sign);
                sign=-1;
                number=0;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                number=0;
                sign=1;
            }
            else if(s[i]==')'){
                result+=(number*sign);
                sign=1;
                long long last_sign=st.top();
                st.pop();
                long long last_result=st.top(); st.pop();
                result=last_result+(result*last_sign);
                number=0;
                sign=1;
            }
        }
        result+=(number*sign);
        return result;
    }
};