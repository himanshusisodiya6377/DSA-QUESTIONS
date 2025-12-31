class Solution {
public:
    int calculate(string s) {
        long long n=s.length();
        if(n==0) return 0;
        long long curr_num=0;
        char sign='+';
        stack<long long>st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isdigit(ch)){
                curr_num=curr_num*10+(ch-'0');
            }
             if((!isdigit(ch) && ch!=' ') || i==n-1){
                if(sign=='+'){
                    st.push(curr_num);
                }
                else if(sign=='-'){
                    // cout<<-curr_num;
                    st.push(-curr_num); 
                }
                else if(sign=='*'){
                    long long t=st.top();
                    st.pop();
                    st.push(curr_num*t);
                }
                else{
                    long long t=st.top();
                    st.pop();
                    st.push(t/curr_num);
                }
                curr_num=0;
                sign=ch;
            }
        }

        // if(curr_num>0) st.push(curr_num);
        long long res=0;

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        return res;
    }
};