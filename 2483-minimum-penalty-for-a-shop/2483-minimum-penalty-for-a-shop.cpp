class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int pre[n+1];
        int suff[n+1];
        int ans[n+1];
        for(int i=0;i<n;i++){ //prefix for N
            pre[0]=0;
             if(customers[i]=='N') pre[i+1]=pre[i]+1;
             else pre[i+1]=pre[i];
        }
        for(int i=n-1;i>=0;i--){
            suff[n]=0;
            if(customers[i]=='Y') suff[i]=suff[i+1]+1;
            else suff[i]=suff[i+1];
        }
        for(int i=0;i<=n;i++){
            ans[i]=pre[i]+suff[i];
        }
        int min=INT_MAX;
         int idx=-1;
        for(int i=0;i<=n;i++){
            if(ans[i]<min){
              min=ans[i];
              idx=i;
            }
        }
        return idx;
    }
};