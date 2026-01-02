class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n=s1.length();
        int m=s2.length();
        int i=0,j=0;
        int ans=INT_MAX;
        int idx=-1;
        int k=0;
        
        while(i<n){
            //moving i to match both string first
            while(i<n && s1[i]!=s2[0]) i++;
             
            //moving j to match both string
            j=i;
            k=0;
            while(j<n && k<m){
                if(s1[j]==s2[k]){
                    j++;
                    k++;
                }
                else j++;
            }
            
            if(k==m){
                if(j-i<ans){
                    ans=j-i;
                    idx=i;
                }
            }
            
            i++;
        }
        if(idx==-1) return "";
        return s1.substr(idx,ans);
    }
};
