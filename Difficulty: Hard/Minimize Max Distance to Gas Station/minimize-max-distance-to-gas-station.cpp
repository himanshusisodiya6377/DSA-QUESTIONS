class Solution {
  public:
    bool check(vector<int>&stations,double mid,int k){
        int n=stations.size();
        // if(n>0 && mid==0.0) return false;
        for(int i=0;i<n-1;i++){
            int diff=stations[i+1]-stations[i];
            if(diff<=mid) continue;
            
            int put=(int)(diff)/mid;
            
            k-=put;
        }
        
        return k>=0;
    }
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n=stations.size();
        double lo =1e-6,hi=stations.back()-stations.front();
        double ans=0;
        while(hi - lo > 1e-6){
            double mid=lo+(hi-lo)/2.0;
            // cout<<mid<<endl;
            // cout<<lo<<" "<<hi<<endl;
            if(check(stations,mid,K)){
                ans=mid;
                // cout<<ans<<endl;
                hi=mid;
            }
            else lo=mid;
        }
        
        return ans;
    }
};