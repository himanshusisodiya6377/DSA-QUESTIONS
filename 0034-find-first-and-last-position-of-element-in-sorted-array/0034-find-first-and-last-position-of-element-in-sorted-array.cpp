class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int n=nums.size();
      vector<int>v={-1,-1};
      if(n==0) return v;
      if(n==1){
        if(nums[0]==target){
            v[0]=0;
            v[1]=0;
            return v;
        }
        else {
            return v;
        }
      }
      int lo=0,hi=n-1;
      while(lo<=hi){
        int mid=(hi+lo)/2;
        if(nums[mid]<target) lo=mid+1;
        else if(nums[mid]>target) hi=mid-1;
        else{
            if(mid==0){
                v[0]=mid;
                int k=mid;
                int j=1;
                 while(j<n && nums[mid+j]==target) {
                    k++;
                    j++;
            }
            v[1]=k;
            return v;
            }
            else if(mid==n-1){
                int j=1;
                int k=mid;
                while(k>0 && nums[n-1-j]==target) {
                    k--;
                    j++;
            }
            v[0]=k;
            v[1]=mid;
            return v;
        }
        else{
            int pre=mid;
            int pro=mid;
            int j=0;
            if(nums[mid-1]==target){
                while(pre>0 && nums[mid-1-j]==target){
                    pre--;
                    j++;
                }
            }
            j=0;
            if(nums[mid+1]==target){
                while(pro<n-1 && nums[mid+1+j]==target){
                    j++;
                    pro++;
                }
            }
            v[0]=pre;
            v[1]=pro;
            return v;
        }
      }
    
    }
      return v;
    }
};