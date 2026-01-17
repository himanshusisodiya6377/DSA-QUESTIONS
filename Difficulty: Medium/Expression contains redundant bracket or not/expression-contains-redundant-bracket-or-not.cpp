class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        int n=s.length();
        stack<char>st;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                int cnt=0;
                while(!st.empty() && st.top()!='('){
                    cnt++;
                    st.pop();
                }
                
                st.pop();
                
                if(cnt==0 || cnt==1) return true;
            }
            else{
                st.push(s[i]);
            }
        }
        return false;
    }
};
