class Solution {
public:
    // bool check(string s){
    //     int n=s.length();
    //     if(n%2==0){
    //         string first=s.substr(0,n/2);
    //         string second=s.substr(n/2,n/2);
    //         reverse(first.begin(),first.end());
    //         if(first==second) return true;
    //         else return false;
    //     }
    //     else{
    //         string first=s.substr(0,n/2);
    //         string second=s.substr((n/2)+1,n/2);
    //         reverse(first.begin(),first.end());
    //         if(first==second) return true;
    //         else return false;
    //     }
    // }
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(n<k) return false;
        vector<int>v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(v[i]%2!=0) count++;
        }
        if(count>k) return false;
        return true;
        // int i=0,j=1;
        // while(k>0 && j<n){
        //    if(check(s.substr(i,j-i+1))){
        //       k--;
        //       i=j+1;
        //       j=i;
        //    }
        //    else{
        //     j++;
        //    }
        // }
        // if(k==0) return true;
        // else return false;
    }
};