class Solution {
public:
    bool check(vector<int>& houses,long long mid,vector<int>& heaters){

        long long i=0,j=0;

        while(i<houses.size() && j<heaters.size()){
            if(((heaters[j]-mid)<=houses[i]) && houses[i]<=heaters[j]){
                i++;
            }
            else if(((heaters[j]+mid>=houses[i])) && houses[i]>=heaters[j]) i++;
            else j++;
        }
        
        if(i<houses.size()) return false;

        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long long n=houses.size();
        long long m=heaters.size();

        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        long long lo=0,hi=1e10;
        // cout<<hi<<endl;
        long long ans;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            
                // cout<<mid<<endl;
            if(check(houses,mid,heaters)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
    }
};