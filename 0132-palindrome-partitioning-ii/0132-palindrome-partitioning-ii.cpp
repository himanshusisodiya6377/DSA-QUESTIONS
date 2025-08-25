class Solution {
public:
    
    //first partition problem

    bool palindrome(int i,int j,string &s){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }

    int solve(int i,int j,string &s,vector<vector<int>>&dp){
 
          if(i==j || i>j) return 0;

          if(palindrome(i,j,s)) return dp[i][j]=0;

          if(dp[i][j]!=-1) return dp[i][j];

               int ans=INT_MAX;

           for(int k=i;k<=j;k++){
            int sum;
            if(palindrome(i,k,s)){
               sum=1+solve(k+1,j,s,dp);
            ans=min(ans,sum);
            }
        }

        if(ans==INT_MAX) return dp[i][j]=0;

        return dp[i][j]=ans;

    }

    int minCut(string s) {
        int n=s.length();

        if(palindrome(0,s.length()-1,s)) return 0;

        int ans=INT_MAX;

        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int i=0;i<n-1;i++){
            int sum;
            if(palindrome(0,i,s)){
               sum=1+solve(i+1,n-1,s,dp);
            ans=min(ans,sum);
            }
        }

        if(ans==INT_MAX) return 0;

        return ans;

    }
};