class Solution {
public:
    int check(vector<int>v,int n,int k){
        int count=0;
        int req=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=n) count++;
            else {
                req+=(count/k);
                count=0;
            }
        }
         req+=(count/k);
        return req;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long n=bloomDay.size();
        if(n<(long)m*k) return -1;
        long lo=1,hi=1000000001;
        long mini=INT_MAX;
        while(lo<=hi){
            long mid=(lo+hi)/2;
            long x=check(bloomDay,mid,k);
            if(x>=m){
                 hi=mid-1;
                 if(mini>mid) mini=mid;
            }
            else lo=mid+1;
        }
      return (long)mini;
    }
};