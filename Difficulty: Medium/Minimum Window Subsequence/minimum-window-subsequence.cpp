class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n=s1.length();
        int m=s2.length();
        int i=0,j=0;
        int ans=INT_MAX;
        int idx=-1;
        // int k=0;
        
        while(i<n){
            //moving i to match both string first
            if(s1[i]==s2[j]){
                j++;
                
                if(j==m){
                    int end=i;
                    j--;
                    
                    while(j>=0){
                        if(s1[i]==s2[j]) j--;
                        i--;
                    }
                    
                    j=0;
                    i++;
                    
                    if(end-i+1<ans){
                        ans=end-i+1;
                        idx=i;
                    }
                }
            }
            i++;
        }
        if(idx==-1) return "";
        return s1.substr(idx,ans);
    }
};
