class Solution {
public:
    int bestClosingTime(string customers) {
         int n=customers.size();
        vector<int>pre(n+1,0);
        vector<int>suff(n+1,0);
        vector<int>ans(n+1,0);
       //for N in the string
       for(int i=1;i<n+1;i++){
        if(customers[i-1]=='N') suff[i]+=(suff[i-1]+1);
        else suff[i]+=(suff[i-1]+0);
        // cout<<suff[i-1]<<" ";
       }
       cout<<endl;
       //for Y in the string
       for(int i=n-1;i>=0;i--){
        if(customers[i]=='Y') pre[i]+=(pre[i+1]+1);
        else pre[i]+=(pre[i+1]+0);
       // cout<<pre[i]<<" ";
       }
       cout<<endl;
       for(int i=0;i<n+1;i++){
          ans[i]=pre[i]+suff[i];
          cout<<ans[i]<<" ";
       }
       
       int min=INT_MAX;
       int idx=-1;
       for(int i=0;i<n+1;i++){
        if(min>ans[i]){
            min=ans[i];
            idx=i;
        }
       }
       return idx;
    }
};