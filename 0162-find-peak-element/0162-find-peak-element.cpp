class Solution {
public:
    int findPeakElement(vector<int>& arr) {
     int n=arr.size();
        int lo=0,hi=n-1;//optimum approach
        if(n==1) return 0;
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

    }
};