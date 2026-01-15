class Solution {
  public:
    bool check(vector<int>&stalls,int mid,int k){
        int n=stalls.size();
        int i=0,j=0;
        k--;
        while(k>0 && j<n){
            while(j<n && abs(stalls[j]-stalls[i])<mid) j++;
            i=j;
            if(j>=n) break;
            k--;
        }
        
        return k<=0;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int lo=1,hi=1e8;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(stalls,mid,k)){
                ans=mid;
            // cout<<ans<<endl;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        
        return ans;
    }
};