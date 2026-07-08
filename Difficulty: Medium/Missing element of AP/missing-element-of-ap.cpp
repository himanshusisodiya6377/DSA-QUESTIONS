class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        // sort(arr.begin(),arr.end());
        
        int d=min(abs(arr[1]-arr[0]),abs(arr[n-1]-arr[n-2]));
        if(arr[0]>arr[1]) d=-d;
        
        int lo=0,hi=n-1;
        
        int ans=arr[0]+n*d;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
             int val=arr[0]+(mid)*d;
            //  cout<<mid<<" "<<val<<endl;
        
            if(arr[mid]==val) {
                lo=mid+1;
            }
            else{
                ans=val;
                hi=mid-1;
            }
                // cout<<mid<<endl;
        }
        
        return ans;
    }
};