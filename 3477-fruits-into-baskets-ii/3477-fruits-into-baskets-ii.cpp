class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j] && v[j]==0) {
                    v[j]=1;
                    break;
                    }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[i]==0) ans++;
        }
        return ans;
    }
};