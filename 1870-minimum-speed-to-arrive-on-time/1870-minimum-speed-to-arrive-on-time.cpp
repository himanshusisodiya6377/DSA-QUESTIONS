class Solution {
public:
    bool check(vector<int>&dist,int mid,double hour){

        int n=dist.size();
        double time=0;

        for(int i=0;i<n;i++){
            if(time>=hour) return false;
            time=ceil(time);
            double res=(double)dist[i]/mid;
            // cout<<res<<endl;
            time+=res;
            // hour-=res;
            // cout<<time<<endl;
        }
        
        if((hour-time)<0) return false;

        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int lo=1,hi=10000001;
        
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            // cout<<mid<<endl;
            if(check(dist,mid,hour)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};