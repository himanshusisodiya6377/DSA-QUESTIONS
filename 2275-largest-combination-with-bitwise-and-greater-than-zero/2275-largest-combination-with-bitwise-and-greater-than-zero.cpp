class Solution {
public:
    int largestCombination(vector<int>& can) {
        int n=can.size();

        vector<int>v(32,0);
        int ans=0;

        for(auto &it : can){
            for(int i=0;i<32;i++){
                if((it>>i)&1){
                    v[i]++;
                    ans=max(ans,v[i]);
                }
            }
        }

        return ans;
    }
};