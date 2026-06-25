class Solution {
public:
    bool check(string &s,string &t,string &Or){
        int i=0,j=0;

        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else break;
        }
        if(i>=s.length()) return true;
        if(i<s.length() && j>=t.length()) return false;

        for(int k=0;k<26;k++){
            if(Or[k]==s[i]) return true;
            if(Or[k]==t[j]) return false;
        }

        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();

        for(int i=0;i<n-1;i++){
            if(!check(words[i],words[i+1],order)) return false;
        }
        return true;
    }
};