class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int maxi=0;
        int ans=0;
        sort(begin(tokens),end(tokens));
        int i=0,j=n-1;
        while(i<=j){
            if(power>=tokens[i]){
                ans++;
                power-=tokens[i];
                i++;
            }
            else{
                if(ans>0 && i!=j){
                    ans--;
                    power+=tokens[j];
                    j--;
                }
                else break;
            }
        }
        // for(int i=0;i<n;i++){
        //    if(power>=tokens[i]){
        //      ans++;
        //      maxi=max(maxi,ans);
        //      power-=tokens[i];
        //    }
        //    else{
        //     if(ans>0){
        //         ans--;
        //         maxi=max(maxi,ans);
        //         power+=tokens[i];
        //     }
        //    }
        // }
        // return maxi;
        return ans;
    }
};