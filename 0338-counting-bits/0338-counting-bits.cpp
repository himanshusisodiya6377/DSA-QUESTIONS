class Solution {
public:
    // void check(vector<int>&ans,int n){
    //     int cnt=0;
    //     if(n==0) {
    //         ans.push_back(0);
    //         return;
    //     }
    //     while(n>1){
    //         if(n%2==1) cnt++;
    //         n/=2;
    //     }
    //     cnt++;
    //     ans.push_back(cnt);
    // }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            // check(ans,i);
            int x=__builtin_popcount(i);
            ans.push_back(x);
        }
        return ans;
    }
};