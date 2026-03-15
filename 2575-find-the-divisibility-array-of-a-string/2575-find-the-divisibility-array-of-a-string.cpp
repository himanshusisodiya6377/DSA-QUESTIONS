class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n=word.size();
        vector<int>ans(n,0);

        unsigned long long rem=0;
        for(int i=0;i<n;i++){
            int x=(word[i]-'0');
            rem=((1LL*rem*10)%m+x%m)%m;
            rem=rem%m;
            if(rem==0) ans[i]=1;
        }
        return ans;
    }
};