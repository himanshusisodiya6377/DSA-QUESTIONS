class Solution {
public:
    int solve(string &a){
        vector<int>ch(26,0);
        int maxi=0;
        int mini=INT_MAX;
        for(auto it : a){
            ch[it-97]++;
            // maxi=max(maxi,ch[it-97]);
            // mini=min(mini,ch[it-97]);
        }
        for(auto it : ch){
            if(it!=0){
            mini=min(mini,it);
            maxi=max(maxi,it);
            }
        }
        // cout<<maxi<<" "<<mini<<endl;
        return maxi-mini;
    }
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            // for(int j=i;j<s.length();j++){
                for (int j = i; j < s.length(); j++) {
                     string a = s.substr(i, j - i + 1);
                     ans += solve(a);
                }
            // }
        }
        return ans;
    }
};