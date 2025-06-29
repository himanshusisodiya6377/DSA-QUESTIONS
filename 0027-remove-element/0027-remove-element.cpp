class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1 && nums[0]!=val) return 1;
        if(n==1 && nums[0]==val) return 0;
        int count=0;
        int i=0,j=1;
        while(i<n && j<n){
            if(nums[i]==val && nums[j]!=val){
                swap(nums[i],nums[j]);
            }
            while(i<n && nums[i]!=val) {
                i++;
                j=i;
                count++;
            }
            while(j<n && nums[j]==val) j++;
        }
        return count;
    }
};