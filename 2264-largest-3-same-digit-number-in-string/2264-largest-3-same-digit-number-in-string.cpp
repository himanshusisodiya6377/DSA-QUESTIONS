class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        string s="";
        string ans="";
        for(int i=1;i<n-1;i++){
         if(num[i]==num[i+1] && num[i]==num[i-1]){
            s+=num[i];
         }
        }
        sort(s.begin(),s.end());
        int m=s.length();
        if(m!=0) for(int i=0;i<3;i++) ans+=s[m-1];
        return ans;
    }
};