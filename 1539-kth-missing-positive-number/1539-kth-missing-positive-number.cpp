class Solution {
public:
    int lower(vector<int>v,int n){
        int lo=0,hi=v.size()-1;
        int mini=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(v[mid]<=n){
             lo=mid+1;
            }
            else hi=mid-1;
        }
        return lo;
    }
    int findKthPositive(vector<int>& arr, int k) {
         int n=arr.size();
        int lo=0,hi=(arr[n-1]+k);
          int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
             int missing = mid - lower(arr, mid);
            if(missing>=k){
              ans=mid;
              hi=mid-1;
            }
            else lo=mid+1;

        }
        return ans;
    }
};