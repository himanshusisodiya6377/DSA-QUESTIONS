class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n=s.length();
        vector<pair<char,int>>suff(n);
        suff[n-1]={s[n-1],n-1};
        for(int i=n-2;i>=0;i--){
            if(s[i]>suff[i+1].first){
                suff[i]={s[i],i};
            }
            else suff[i]=suff[i+1];
        }
        
        // for(auto it : suff){
        //     cout<<it.first<<" "<<it.second<<" ";
        // }
        for(int i=0;i<n-1;i++){
            if(s[i]<suff[i].first){
                swap(s[i],s[suff[i].second]);
                break;
            }
        }
        
        return s;
    }
};