class Solution {
public:
    int solve(int n){
        if(n==0) return 1;

        if(n==1) return 1;

        int ans=0;

        for(int i=1;i<=n;i++){
            int lf=solve(i-1);
            int rg=solve(n-i);
            ans+=(lf*rg);
        }

        return ans;
    }
    int numTrees(int n) {
        return solve(n);
    }
};