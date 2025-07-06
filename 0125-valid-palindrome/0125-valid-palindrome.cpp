class Solution {
public:
 
    bool check(string a){
        int n=a.size();
        // if(n==1) return false;
        if(n%2==0){
            string temp=a.substr(0,n/2);
            string get=temp;
            reverse(temp.begin(),temp.end());
            get+=temp;
            if(get==a) return true;
    
        }
        else{
            string temp=a.substr(0,n/2);
            char ch=a[n/2];
            string get=temp;
            reverse(temp.begin(),temp.end());
            get.push_back(ch);
            get+=temp;
            if(get==a) return true;
          
        }
        return false;
    }
    
    bool isPalindrome(string s) {
        int n=s.length();
        if(n==0) return false;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z') ans.push_back(s[i]);
            else if(s[i]>='A' && s[i]<='Z') ans.push_back((char)(s[i]+32));
            else if(s[i]>='0' && s[i]<='9') ans.push_back(s[i]);
        }
        if(check(ans)) return true;
        return false;
    }
};