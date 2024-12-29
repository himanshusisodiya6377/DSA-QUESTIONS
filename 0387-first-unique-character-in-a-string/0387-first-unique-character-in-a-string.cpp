class Solution {
public:
    int firstUniqChar(string s) {
        // sort(s.begin(),s.end());
        vector<int>v(26,0);
        int n=s.length();
        bool flag;
        for(int i=0;i<n;i++){
              int x=s[i]-97;
           if(v[x]==0) flag=false;
            for(int j=i+1;j<n;j++){
               
                 if(v[x]!=0) break;;
                if(s[i]==s[j]) {
                    v[x]++;
                    flag=true;
                    break;
                }
                 
            }
            if(flag==false) return i;
           
        }
        return -1;
    }
};