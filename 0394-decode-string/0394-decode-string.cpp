class Solution {
public:
    string decodeString(string s) {
        int n=s.length();
        stack<string>st;
         
        string ans="";

        for(int i=n-1;i>=0;i--){
            if(s[i]=='['){
                 string temp="";
                 while(!st.empty() && st.top()!="]"){
                    temp +=st.top();
                    st.pop();
                 }
                //  cout<<"h"<<endl;
                //  cout<<st.size()<<endl;
                 st.pop();
                //  cout<<"nikal"<<endl;
                 i--;
                 int k=0;
                //  cout<<i<<endl;
                 stack<char>num;
                 while(i>=0 && isdigit(s[i])){
                    //   int x=s[i]-48;
                    //   k+=x;
                    //   k*=10;
                    num.push(s[i]);
                    // cout<<"yes"<<endl;
                    i--;
                 }
                 i++;

                 while(!num.empty()){
                    int x=num.top()-'0';
                    // cout<<x;
                    // k+=x;
                    k=k*10+x;
                    num.pop();
                 }
                 string copy=temp;
                //  k/=10;
                // cout<<k<<endl;
                 while(k>1) {
                    temp+=copy;
                    // cout<<temp<<endl;
                    k--;
                 }
                //  cout<<temp<<endl;
                 st.push(temp);
            }
            else{
                st.push(string(1, s[i]));
                // cout<<st.top()<<endl;
            }
        }
      
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            // cout<<"yes"<<endl;
        }
        return ans;
    }
};