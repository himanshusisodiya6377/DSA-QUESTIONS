class Solution {
public:
    string removeDuplicates(string s) {
     int n=s.length();
    //  string ans="";
    //  for(int i=0;i<n;i++){
    //     ans.push_back(s[i]);
    //     if(ans.size()>=2){
    //         if(ans[ans.size()-1]==ans[ans.size()-2]) ans.erase(ans.size()-2,2);
    //     }
    //  }   


    //TC-O(n*m) SC-O(n)

    // stack<pair<char,int>>st;
    // for(int i=0;i<n;i++){
    //     if(st.size()>0 && st.top().first==s[i]){
    //         st.top().second++;
    //         if(st.top().second==2) st.pop();
    //     } 
    //     else{
    //         st.push({s[i],1});
    //     }
    // }
    // string ans="";
    // while(st.size()>0){
    //      for(int i=0;i<st.top().second;i++){
    //         ans.push_back(st.top().first);
    //      }
    //      st.pop();
    // }
    // reverse(ans.begin(),ans.end());
    // return ans;

    stack<char>st;
    for(int i=0;i<n;i++){
        if(st.size()>0 && st.top()==s[i]) st.pop();
        else{
            st.push(s[i]);
        }
    }
    string ans="";
    while(st.size()>0){
         char ch=st.top();
         st.pop();
         ans.push_back(ch);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};