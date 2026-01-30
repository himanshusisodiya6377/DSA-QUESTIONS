class Solution {
public:
    string getSmallestString(string s, int k) {
        if(k==0) return s;
        int n=s.length();
        string t=s;
        for(int i=0;i<n && k>0;i++){
            // cout<<(t[i]-'a')-97<<" "<<123-(t[i]-'a')<<endl;
          int diff = min(t[i] - 'a', 'z' - t[i] + 1);
           cout<<diff<<endl;
           if(diff<=k){
            t[i]='a';
            k-=diff;
           }
           else{
            t[i]-=k;
            k=0;
           }
        }

        return t;
    }
};