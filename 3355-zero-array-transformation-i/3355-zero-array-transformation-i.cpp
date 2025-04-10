class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int r=queries.size();
        vector<int>diff(n,0);
        for(int i=0;i<r;i++){
            diff[queries[i][0]]-=1;
            if(queries[i][1]+1<n) diff[queries[i][1]+1]+=1;
        }
         for(int i=1;i<n;i++) diff[i]+=diff[i-1];
         for(int i=0;i<n;i++){
            nums[i]+=diff[i];
         }
         for(int i=0;i<n;i++){
            if(nums[i]>0) return false;
         }
         return true;
    }
};