class Solution {
public:
    int maxScore(string s) {
      int n=s.length();
      vector<int>pre(n,0);
       vector<int>suff(n,0);
      //getting pre that stores zeroes
      if(s[0]=='0') pre[0]=1;
      if(s[n-1]=='1') suff[n-1]=1;
      for(int i=1;i<n;i++){
          if(s[i]=='0') pre[i]+=(pre[i-1]+1);
          else pre[i]=pre[i-1];
      }
      pre.pop_back();
      //0 1 1 1 1 2 
      
      //getting pre that stores zeroes
      for(int i=n-2;i>=0;i--){
          if(s[i]=='1') suff[i]+=(suff[i+1]+1);
          else suff[i]=suff[i+1];
      }
      suff.erase(suff.begin());
      vector<int>ans(n-1,0);
      for(int i=0;i<n-1;i++) ans[i]+=(pre[i]+suff[i]);
      sort(ans.begin(),ans.end());
      return ans[n-2];
    }
};