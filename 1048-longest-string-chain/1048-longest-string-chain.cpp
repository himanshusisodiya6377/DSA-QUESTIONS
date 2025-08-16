class Solution {
public:

    bool check(string main,string temp){
        int i=0,j=0;
        if(abs((long long)(main.length()-temp.length()))!=1) return false;
        bool flag=false;

        while(i<main.size() && j<temp.size()){
            if(main[i]==temp[j]){
                i++;
                j++;
            }
            else if(flag==false){
                i++;
                flag=true;
            }
            else return false;
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
});
        int n=words.size();
        vector<int>dp(n,1);

        int maxi=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }

        for(auto it : dp){
            maxi=max(maxi,it);
        }

        return maxi;
    }
};