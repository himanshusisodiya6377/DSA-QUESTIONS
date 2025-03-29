class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
     int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ans++;
        }
        int k=0,m=0;
        int count=0;
        while(m<n){
              if(s[k]=='1' && s[m]=='1'){
                k++;
                m++;
            }
            else if(s[k]=='0' && s[m]=='0') m++;
            else{
                count++;
                k=m;
            }
        }
        if(k!=m) count++;
        if(count==1) return ans;
        int first=0;
        int second=0;
        int maxi=INT_MIN;
        int i=0,j=0;
        while(j<n){
            if(s[i]=='1' && s[j]=='1'){
                i++;
                j++;
            }
            else if(s[i]=='0' && s[j]=='0') j++;
            else{
                second=first;
                first=(j-i);
                if(first!=0 && second!=0){
                int sum=first+second;
                if(maxi<sum) maxi=sum;
                }
                i=j;
            }
        }
         second=first;
         first=(j-i);
         int sum=first+second;
         if(maxi<sum) maxi=sum;
        ans+=maxi;
        return ans;
    }
};