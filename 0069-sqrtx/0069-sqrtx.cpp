class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1 ) return x;
       int lo=0,hi=x-1;
       int ans=-1;
       while(lo<=hi){
        long long mid=(lo+hi)/2;
        if((mid*mid)<=(long long )x){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
       } 
       return ans;
    }
};