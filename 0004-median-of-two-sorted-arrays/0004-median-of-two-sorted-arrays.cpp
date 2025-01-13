class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         vector <int> v;
        int n = nums1.size();
        int m = nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
    
        }
        if(i==n){
            while(j<m){
                v.push_back(nums2[j]);
                j++;
            }
        }
        if(j==m){
            while(i<n){
                v.push_back(nums1[i]);
                i++;
            }
        }
        int l=v.size();
        if(l%2==0) return double(v[(l/2)-1]+v[l/2])/2;
        else return double(v[l/2]);
    //       int n=nums1.size();
    //  int m=nums2.size();
    // // int lo=0,hi=n+m-1;
    //  //int mid=(lo+hi)/2;
    // // int avg=0;
    //  vector<int>v;
    //  int i=0,j=0;
    //  while(i<n && j<m){
    //      if(nums1[i]<nums2[j]){
    //          v.push_back(nums1[i]);
    //          i++;
    //      }
    //      else {
    //          v.push_back(nums2[j]);
    //          j++;
    //      }
    //  }
    //  if(i==n){
    //      while(j<m){
    //          v.push_back(nums2[j]);
    //          j++;
    //      }
    //  }
    // if(j==m){
    //      while(i<n){
    //          v.push_back(nums1[i]);
    //          i++;
    //      }
    //  }
    
     
    //  int k=v.size();
    //  if(k%2!=0) return double(v[k/2]);
    //  else return  double((v[(k/2)-1]+v[k/2])/2);
    }
};