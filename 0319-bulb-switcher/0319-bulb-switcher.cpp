class Solution {
public:
    bool check(int mid,int n){
          long long int multi=(long long )mid*mid-mid;
          long long int x=mid+multi;
          if(x<=n) return true;
          else return false;
    }
    int bulbSwitch(int n) {
        if(n==1 || n==2) return 1;
        int lo=1,hi=n;
        int mid;
        while(lo<=hi){
           mid=(lo+hi)/2;
            if(check(mid,n)) lo=mid+1;
            else hi=mid-1;
        }
        return hi;
    }
};