class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        if(m%2==0){
            for(int i=0;i<m;i++){
                ans^=nums2[i];
            }
            int temp=ans;
            for(int i=1;i<n;i++){
                 ans^=temp;
            }
        }
        else{
            for(int i=0;i<m;i++){
                ans^=nums2[i];
            }
            int temp=ans;
            for(int i=1;i<n;i++){
                 ans^=temp;
            }
            for(int i=0;i<n;i++){
                ans^=nums1[i];
            }
        }
       return ans;
    }
};