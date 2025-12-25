class Solution {
public:
    bool is_match(unordered_map<char,int>&sm,unordered_map<char,int>&tm){
        for(auto &it : tm){
            if(sm.find(it.first)!=sm.end()){
                if(sm[it.first]<it.second) return false;
            }
            else return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m>n) return "";
        int lf=-1,rg=-1;
        int ans=INT_MAX;
        int i=0,j=0;
        unordered_map<char,int>sm;
        unordered_map<char,int>tm;
        for(auto &it : t) tm[it]++;
        while(j<n){
           sm[s[j]]++;
           while(i<=j && is_match(sm,tm)==true){
              if(j-i+1<ans){
                ans=j-i+1;
                lf=i;
                rg=j;
              }
              sm[s[i]]--;
              i++;
           }
           j++;
        }
        if(lf==-1 && rg==-1) return "";
        return s.substr(lf,rg-lf+1);
    }
};