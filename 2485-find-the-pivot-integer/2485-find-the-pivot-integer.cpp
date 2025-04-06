class Solution {
public:
    int pivotInteger(int n) {
        vector<int>pre(n+1,0);
        vector<int>suff(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=i+pre[i-1];
        }
        suff[n]=n;
        for(int i=n-1;i>=0;i--){
         suff[i]=i+suff[i+1];
        }
        for(int i=0;i<=n;i++){
            if(pre[i]==suff[i]) return i;
        }
        return -1;
    }
};