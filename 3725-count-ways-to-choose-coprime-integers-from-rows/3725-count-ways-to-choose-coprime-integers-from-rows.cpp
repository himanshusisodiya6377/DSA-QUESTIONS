class Solution {
public:
    int mod=1e9+7;
    vector<vector<unordered_map<int,int>>> dp;
    int gcd(int a,int b){
        if(a==0) return b;
        return gcd(b%a,a);
    }
    int solve(int i,int j,vector<vector<int>>&mat,int gd){
        if(i>=mat.size() || i<0 || j<0 || j>=mat[0].size()){
            if(gd==1) return 1;
            return 0;
        }        
        if (dp[i][j].count(gd))
            return dp[i][j][gd];
        long long ans=0;
        for(int k=0;k<mat[0].size();k++){
                int num=gcd(gd,mat[i][k]);
                ans=(ans+solve(i+1,k,mat,num))%mod;
            }
        

        return dp[i][j][gd]=ans;
    }
    int countCoprime(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
         dp.resize(r, vector<unordered_map<int,int>>(c));
        if(r==1){
            long long ans=0;
            for(int i=0;i<c;i++){
                if(mat[0][i]==1) ans++;
            }
                return ans%mod;
        }

        long long ans=0;
        for(int i=0;i<c;i++){
            ans=(ans+solve(1,i,mat,mat[0][i]))%mod;
        }

        return ans%mod;
    }
};