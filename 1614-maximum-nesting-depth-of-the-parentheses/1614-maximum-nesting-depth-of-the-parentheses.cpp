class Solution {
public:
    int maxDepth(string s) {
      int maxi=0;
      int n=s.length();
      stack<char>st;
      int count=0;
      for(int i=0;i<n;i++){
        if(s[i]=='(') st.push(s[i]);
        if(s[i]==')' && st.size()>0){
                st.pop();
                if(st.size()+1>maxi) maxi=st.size()+1;
        }
      }
    //     if(st.size()==0){
    //         if(maxi<count){
    //             maxi=count;
    //             count=0;
    //         }
    //     }
    //   }  
      return maxi;
    }
};