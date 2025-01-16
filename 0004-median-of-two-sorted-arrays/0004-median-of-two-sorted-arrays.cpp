class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int n1=nums1.size();
     int n2=nums2.size();
     if(n2==0) {
        int mid=(n1+1)/2;
        if(n1%2!=0) return (double)nums1[mid-1];
        else{
            return (double)((nums1[mid]+nums1[mid-1])/2.0);
        }
     }
     if(n1==0) {
        int mid=(n2+1)/2;
        if(n2%2!=0) return (double)nums2[mid-1];
        else{
            return (double)((nums2[mid]+nums2[mid-1])/2.0);
        }
     }
     int n=n1+n2;
     if(n1>n2) return findMedianSortedArrays(nums2,nums1);
     int left=(n1+n2+1)/2;
     int lo=0,hi=n1;
     while(lo<=hi){
        int mid1=(lo+hi)>>1;
        int mid2=left-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];
        if(mid1-1>=0) l1=nums1[mid1-1];
        if(mid2-1>=0) l2=nums2[mid2-1];
        if(l1<=r2 && l2<=r1) {
            if(n%2==1) return max(l1,l2);
            else return (double)((max(l1,l2)+min(r1,r2))/2.0);
        }
        else if(l1>r2) hi=mid1-1;
        else lo=mid1+1;
     }
     return -1;
    }
};