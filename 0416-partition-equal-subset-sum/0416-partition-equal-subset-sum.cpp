class Solution {
public:
   int t[201][20001];
    bool issubsetsum(vector<int>&nums,int target){
        int n=nums.size();
        //intialisation
        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(i==0) t[i][j]=false;
                if(j==0) t[i][j]=true;
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j] || t[i-1][j-nums[i-1]];
                }
                else t[i][j]=t[i-1][j];
            }
        }
      return t[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto v : nums) sum+=v;
        if(sum%2!=0) return false;
        return issubsetsum(nums,sum/2);
    }
};