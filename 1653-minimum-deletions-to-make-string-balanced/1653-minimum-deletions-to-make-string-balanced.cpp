class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        if(n==1) return 0;
        vector<int>pre(n,0);
        if(s[0]=='b') pre[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='a') pre[i]=pre[i-1];
            else pre[i]=1+pre[i-1];
        }

        // if(pre[n-1]==0) return 0;

        // for(auto &it : pre) cout<<it<<" ";
        // cout<<endl;
        vector<int>suff(n,0);
         if(s[n-1]=='a') suff[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='b') suff[i]=suff[i+1];
            else suff[i]=1+suff[i+1];
        }
         
        //  if(suff[0]==0) return 0;
        //  for(auto &it : suff) cout<<it<<" ";
        // cout<<endl;
        int mini=INT_MAX;
        // for(int i=0;i<n-1;i++){
        //     if(pre[i]==0){
        //         mini=min(mini,pre[i]+suff[i+1]);
        //     }
        //     else break;
        // }
        mini = min(pre[n - 1], suff[0]);
        for(int i=0;i<n-1;i++){
            
                mini=min(mini,pre[i]+suff[i+1]);
            
        }

        return mini;

    }
};