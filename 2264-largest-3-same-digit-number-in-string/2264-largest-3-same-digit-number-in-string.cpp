class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        string s="";
        for(int i=1;i<n-1;i++){
         if(num[i]==num[i+1] && num[i]==num[i-1]){
            if(s.length()==0) s+=num[i];
            else{
                if(s[0]<num[i]) s[0]=num[i];
            }
         }
        }
        if(s.length()!=0) for(int i=0;i<2;i++) s+=s[0];
        return s;
    }
};