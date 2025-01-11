class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(mid==0){
                if(arr[mid]>arr[mid+1]) return mid;
                else lo=mid+1;
            }
            else if(mid==n-1){
                if(arr[mid-1]<arr[mid]) return mid;
                else hi=mid-1;
            }
            else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]<arr[mid+1]) lo=mid+1;
            else hi=mid-1;
        }
        return -1;





        // int  n=arr.size();
        // int lo=0,hi=n-1;
        // while(lo<=hi){
        //    int mid=lo+((hi-lo)/2);
        //      //long long md=(long long)mid;
        //      if(mid==0) return mid+1;
        //     if(arr[mid]<arr[mid-1]) hi=mid-1;
        //     else if(arr[mid]<arr[mid+1]) lo=mid+1;
        //     else return mid;
        // }
        // return -1;
    }
};