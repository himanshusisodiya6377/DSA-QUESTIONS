class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>ans(n,0);

        int fill=0;
        int idx=0;
        bool flag=false;
        sort(deck.begin(),deck.end());
        int j=0;
        while(fill!=n){
            if(ans[idx]==0 && !flag){
                ans[idx]=deck[j];
                fill++;
                j++;
                flag=!flag;
            }
            else if(ans[idx]==0) flag=!flag;
            idx++;
            if(idx==n) idx=0;
        }
        return ans;
    }
};