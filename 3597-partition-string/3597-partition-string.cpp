class Solution {
public:
    vector<string> partitionString(string s) {
        int n=s.length();
        // vector<char>visit(26,0);
       unordered_set<string>st;
       string seg="";
       vector<string>ans;
       for(int i=0;i<n;i++){
        if(seg.length()==0){
            seg.push_back(s[i]);
        }
        else if(st.find(seg)==st.end()){
            st.insert(seg);
            ans.push_back(seg);
            seg="";
            seg.push_back(s[i]);
         }
         else if(st.find(seg)!=st.end()){
            // ans.push_back(seg);
            // seg="";
            seg.push_back(s[i]);
         }
       }
       if(st.find(seg)==st.end()) ans.push_back(seg);
       return ans;
    }
};