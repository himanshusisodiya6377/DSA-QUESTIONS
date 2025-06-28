class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        int i=0,j=2*k-1;
        if(n<k){
            reverse(s.begin(),s.end());
            return s;
        }
        else if(n>=k && n<2*k){
             reverse(s.begin(),s.begin()+k);
             return s;
        }
        else{
            int temp=j;
            while(j<n){
                reverse(s.begin()+i,s.begin()+i+k);
                i+=2*k;
                temp=j;
                j+=2*k;
            }
            int diff=n-temp-1;
            if(diff==0) return s;
            if(diff<k){
                 reverse(s.begin()+i,s.begin()+n);
                 return s;
            }
            else if(diff>=k && diff<2*k){
                reverse(s.begin()+i,s.begin()+i+k);
                return s; 
            }
        }
        return s;
    }
};