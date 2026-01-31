class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        vector<vector<int>>idx(26);
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                idx[s[i]-'a'].push_back(i);
            }
            else{

                for(int j=0;j<26;j++){
                    if(idx[j].size()>0){
                       s[idx[j].back()]='#';
                       idx[j].pop_back();
                       break;
                    }
                }
            }
        }

        cout<<s;

        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]!='#' && s[i]!='*') temp.push_back(s[i]);
        }

        return temp;
    }
};