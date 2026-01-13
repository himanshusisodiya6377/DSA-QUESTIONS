class Solution {
public:
    bool check(int m,int n){
        long long sum=(1LL*m*(m+1))/2;
        if(sum>n) return false;
        return true;
    }
    int arrangeCoins(int n) {
        int lo=0,hi=1e7;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,n)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};