class Solution {
public:
    int count(vector<int>piles, int n){
        int c=0;
        for(int i=0;i<piles.size();i++){
           float y=ceil(1.0*piles[i]/n);
           c+=y;
        }
        return c;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int lo=1,hi=piles[n-1];
        int mini=INT_MAX;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int x=count(piles,mid);
            if(x<=h){
                hi=mid-1;
                 if(mid<mini) mini=mid;
            }
            else lo=mid+1;
        }
        return mini;
    }
};