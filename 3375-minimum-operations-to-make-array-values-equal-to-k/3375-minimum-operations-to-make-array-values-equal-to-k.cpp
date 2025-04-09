class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int count=0;
        int num=nums[n-1];
        int i=n-1;
        if(num==k && n==1) return 0;
        if(num<k && n==1) return -1;
        if(num<=k && nums[0]!=nums[n-1]) return -1;
        while(i>=0){
             while(i>=0 && nums[i]==num) i--;
             if(i<0) break;
             num=nums[i];
             count++;
            //  if(num==k) break;
        }
        if(num<k) return -1;
        if(num>k) count++;
        return count;
    }
};