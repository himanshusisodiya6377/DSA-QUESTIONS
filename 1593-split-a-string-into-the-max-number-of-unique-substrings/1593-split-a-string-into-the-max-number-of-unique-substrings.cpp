class Solution {
public:
    int n;
    int ans=0;
    unordered_set<string>st;
    void  solve(string &s,int idx,int count){
        if (count + (s.length() - idx) <= ans) return;
         if(idx>=s.length()){
            ans=max(ans,count);
            return;
         }
         int maxi=0;
         for(int i=1;i<=n;i++){
            string temp=s.substr(idx,i);
            if(st.find(temp)==st.end()){
                st.insert(temp);
                solve(s,idx+i,count+1);
                st.erase(temp);
            }
         }

        //  return count;
    }
    int maxUniqueSplit(string s) {
        n=s.length();
        solve(s,0,0);
        return ans;
    }
};