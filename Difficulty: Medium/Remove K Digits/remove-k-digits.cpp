class Solution {
  public:
    string removeKdig(string &num, int k) {
        // code here
            int n=num.length();
        if(n==k) return "0";
        stack<int>st;
        //creating an increasing order with k removals 
        //first thing in notice at instance we got first greater than next remove it
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && num[st.top()]>num[i] && k>0) {
                    st.pop();
                    k--;
                }
                st.push(i);
            }
        }

        // while(!st.empty()){
        //     cout<<st.top()<<" ";
        //     st.pop();
        // }
        //if still k left remove from end as sequence is in increasing order
        while(k>0){
            st.pop();
            k--;
        }

        string ans="";
        while(!st.empty()){
            ans.push_back(num[st.top()]);
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        //truncate intial zeroes
        int j=0;
        while(j<n && ans[j]=='0'){
            // if(num[j]!='0') break;
            j++;
        }

        if(j==ans.length()) return "0";
        return ans.substr(j);
    }
};