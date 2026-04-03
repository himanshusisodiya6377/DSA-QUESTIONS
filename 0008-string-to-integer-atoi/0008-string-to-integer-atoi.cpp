class Solution {
public:
    int myAtoi(string s) {
        long long n=s.length();

         long long  num=0;
         long long  maxi_r=pow(2,31)-1;
         long long  mini_r=-pow(2,31);
        bool flag=false;
        bool reading=false;
        for(int i=0;i<n;i++){
            if(!isdigit(s[i]) && reading) return num;
            else if(s[i]=='-') {
                flag=true;
                reading=true;
            }
            else if(s[i]=='+' && !reading) {
                flag=false;
                reading=true;
            }
            else if(!isdigit(s[i]) && s[i]!=' ') {
                // cout<<"yahi hua he";
                return num;
            }
            else if(isdigit(s[i])){
                num=1LL*num*10+(flag ? -(s[i]-'0') : (s[i]-'0'));
                // cout<<num<<endl;
                if(num<mini_r) num=mini_r;
                else if(num>maxi_r) num=maxi_r;
                reading=true;
            }
        }
        
        return  num;
    }
};