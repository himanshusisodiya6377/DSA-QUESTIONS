class Solution {
public:
    string removeDuplicates(string s, int k) {
     int n=s.length();
     //Time Limit Exceeded

    //  string ans="";
    //  for(int i=0;i<n;i++){
    //     ans.push_back(s[i]);
    //     if(ans.size()>=k){
    //        string sub=ans.substr(ans.size()-k,k);
    //        sort(begin(sub),end(sub));
    //        if(sub[0]==sub[sub.size()-1]){
    //         ans.erase(ans.size()-k,k);
    //        }
    //     }
    //  }   
    //  return ans;   
    stack<pair<char,int>>st;
    for(int i=0;i<n;i++){
        if(st.size()>0 && st.top().first==s[i]){
            st.top().second++;
            if(st.top().second==k) st.pop();
        } 
        else{
            st.push({s[i],1});
        }
    }
    string ans="";
    while(st.size()>0){
         for(int i=0;i<st.top().second;i++){
            ans.push_back(st.top().first);
         }
         st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};