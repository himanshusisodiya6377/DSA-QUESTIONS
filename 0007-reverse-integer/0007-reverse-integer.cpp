class Solution {
public:
    int reverse(int x) {
        string s;
        bool flag=false;
        int n;
        if(x>=0) {
            s=to_string(x);
            n=s.length();
        }
        else {
            flag=true;
            s=to_string(x);
            n=s.length();
            s = s.substr(1, s.length() - 1);
            // cout<<s<<endl;
        }
         
        int i=0,j=(flag ? n-2  :n-1);
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        // cout<<s<<endl;
        int upl=2147483647;
        int downl=-2147483648;

        // cout<<s<<endl;


        long long y=stoll(s);
        if(flag) y=-y;
        if(y>upl || y<downl) return 0;
        // cout<<s.length()<<endl;
        return y;
    }
};