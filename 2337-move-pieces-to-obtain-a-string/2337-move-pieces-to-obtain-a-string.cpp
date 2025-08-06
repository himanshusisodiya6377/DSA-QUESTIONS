class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.length();
        int m=target.length();
        if(m!=n) return false;

        int i=0,j=0;

        while(i<n && j<m){
            if(start[i]=='_' || target[j]=='_'){
                while(i<n && start[i]=='_') i++;
                while(j<m && target[j]=='_') j++;
            }
            else{
                if(start[i]==target[j]){
                    i++;
                    j++;
                }
                else return false;
            }
        }

        if(target[m-1]=='_' && start[n-1]=='R') return false;
        if(target[0]=='_' && start[0]=='L') return false;

        vector<pair<char,int>>str;
        vector<pair<char,int>>tar;

        for(int i=0;i<n;i++){
            if(start[i]!='_') str.push_back({start[i],i});
            if(target[i]!='_') tar.push_back({target[i],i});
        }

        if(str.size()!=tar.size()) return false;

        for(int i=0;i<str.size();i++){
            pair<char,int>st=str[i];
            pair<char,int>tr=tar[i];

            if(st.first!=tr.first) return false;

            if(st.first=='L'){
                if(tr.second>st.second) return false;
            }
            else{
                if(tr.second<st.second) return false;
            }
        }
        
        return true;
    }
};