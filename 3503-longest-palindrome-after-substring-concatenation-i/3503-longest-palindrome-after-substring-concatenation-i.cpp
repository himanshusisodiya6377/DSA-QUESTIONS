class Solution {
public:
    bool check(string &p){
        int i=0,j=p.length()-1;
        while(i<=j){
            if(p[i]!=p[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                string p=s.substr(i,j-i+1);

                for(int k=0;k<m;k++){
                    for(int l=k;l<m;l++){
                       
                       string a=t.substr(k,l-k+1);
                       string b=p+a;
                    //    cout<<b<<endl;
                       if(check(b)) ans=max(ans,(int)b.length());
                    }
                }
            }
        }
        
        //invidually can have 
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string p=s.substr(i,j-i+1);
                // cout<<p<<endl;
                if(check(p)) ans=max(ans,(int)p.length());    
            }
        }

          for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                string p=t.substr(i,j-i+1);
                // cout<<p<<endl;
                if(check(p)) ans=max(ans,(int)p.length());    
            }
        }
        return ans;
    }
};