class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long n=weights.size();
        vector<long long>pair(n-1,0);
        for(int i=0;i<n-1;i++){
            pair[i]=weights[i]+weights[i+1];
        }
        sort(pair.begin(),pair.end());
        long long minsum=0,maxsum=0;
        for(int i=0;i<k-1;i++){
            minsum+=pair[i];
        }
         for(int i=n-2;i>=0 && k-1>0;i--){
            maxsum+=pair[i];
            k--;
        }
    return maxsum-minsum;
    }
};