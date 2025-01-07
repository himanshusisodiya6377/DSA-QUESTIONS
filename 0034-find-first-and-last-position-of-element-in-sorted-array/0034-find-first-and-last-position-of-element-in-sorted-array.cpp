class Solution {
public:
    int upparbound(vector<int>arr,int k){
         int n=arr.size();
       int first=-1;
       int lo=0,hi=n-1;
       while(lo<=hi){
           int mid=(lo+hi)/2;
           if(arr[mid]<=k){
               first=mid;
               lo=mid+1;
           }
           else hi=mid-1;
       }
       return first;
    }
     int lowerbound(vector<int>arr,int k){
         int n=arr.size();
       int last=-1;
       int lo=0,hi=n-1;
       while(lo<=hi){
          int mid=(lo+hi)/2;
           if(arr[mid]>=k){
               last=mid;
               hi=mid-1;
           }
           else lo=mid+1;
       }
       return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
             int x=lowerbound(nums,target);
             int y=upparbound(nums,target);
             if(x>=0 && nums[x]==target) return{x,y};
             else return {-1,-1};
        //BAKWASS APPROACH (1ST MINE APPROACH!!)
    //   int n=nums.size();
    //   vector<int>v={-1,-1};//decalaration of vector
    //   if(n==0) return v;
    //   if(n==1){
    //     if(nums[0]==target){
    //         v[0]=0;
    //         v[1]=0;
    //         return v;
    //     }
    //     else {
    //         return v;
    //     }
    //   }
    //   int lo=0,hi=n-1;
    //   while(lo<=hi){
    //     int mid=(hi+lo)/2;
    //     if(nums[mid]<target) lo=mid+1;
    //     else if(nums[mid]>target) hi=mid-1;
    //     else{
    //         if(mid==0){//if  mid at zero so target to get last occurance
    //             v[0]=mid;
    //             int k=mid;
    //             int j=1;
    //              while(j<n && nums[mid+j]==target) {
    //                 k++;
    //                 j++;
    //         }
    //         v[1]=k;
    //         return v;
    //         }
    //         else if(mid==n-1){ //if mid at n-1 target to get first occurance
    //             int j=1;
    //             int k=mid;
    //             while(k>0 && nums[n-1-j]==target) {
    //                 k--;
    //                 j++;
    //         }
    //         v[0]=k;
    //         v[1]=mid;
    //         return v;
    //     }
    //     else{  //if mid in between
    //         int pre=mid;//for first occurance
    //         int pro=mid;//for  last occurance
    //         int j=0;
    //         if(nums[mid-1]==target){
    //             while(pre>0 && nums[mid-1-j]==target){
    //                 pre--;
    //                 j++;
    //             }
    //         }
    //         j=0;
    //         if(nums[mid+1]==target){
    //             while(pro<n-1 && nums[mid+1+j]==target){
    //                 j++;
    //                 pro++;
    //             }
    //         }
    //         v[0]=pre;
    //         v[1]=pro;
    //         return v;
    //     }
    //   }
    
    // }
    //   return v;
    }
};