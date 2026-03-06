class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        vector<pair<int,int>>pos(26,{-1,-1});

        for(int i=0;i<n;i++){
            if(pos[s[i]-'a'].first==-1) pos[s[i]-'a'].first=i;
            else pos[s[i]-'a'].second=i;
        }

        // for(auto &it : pos){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        int cnt=0;

        for(auto &it : pos){
            if(it.first==-1 || it.second==-1) continue;
            unordered_set<char>st;
            for(int i=it.first+1;i<it.second;i++){
                st.insert(s[i]);
            }
            // cout<<st.size();
            cnt+=st.size();
        }
        return cnt;
    }
};