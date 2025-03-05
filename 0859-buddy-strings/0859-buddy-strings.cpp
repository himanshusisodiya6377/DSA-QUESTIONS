class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.length();
        int m=goal.length();
        if(m!=n) return false;
        vector<int>fir(26,0);
        vector<int>sec(26,0);
        for(int i=0;i<n;i++){
            fir[s[i]-'a']++;
            sec[goal[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(fir[i]!=sec[i]) return false;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]) count++;
        }
        if(count>2) return false;
        else{
            if(count==0){
                for(int i=0;i<26;i++){
                    if(fir[i]>=2) return true;
                }
            }
            else if(count==1) return false;
             else return true;
        }
        return false;
    }
};