class Solution {
public:
    int n;
    unordered_set<string>st;
    int  solve(string &s,int idx){
         if(idx>=s.length()) return 0;
         int maxi=0;
         for(int i=1;i<=n;i++){
            string temp=s.substr(idx,i);
            if(st.find(temp)==st.end()){
                st.insert(temp);
                maxi=max(maxi,1+solve(s,idx+i));
                st.erase(temp);
            }
         }

         return maxi;
    }
    int maxUniqueSplit(string s) {
        n=s.length();
        return solve(s,0);
    }
};