class Solution {
public:
    int countHomogenous(string s) {
        long long n=s.length();
         long long count=1;
         long long m=1000000007;
         long long i=1;
         long long ans=0;
        while(i<n){
            if(s[i]==s[i-1]) count++;
            else{
                ans+=(((count%m)*((count%m)+1))%m/2);
                count=1;
            }
            i++;
        }
         ans+=(((count%m)*((count%m)+1))%m/2);
         return ans;
    }
};