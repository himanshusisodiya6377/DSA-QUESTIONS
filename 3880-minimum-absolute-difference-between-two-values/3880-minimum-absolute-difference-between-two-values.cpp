class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(nums[i]==1 && nums[j]==2){
                    ans=min(ans,abs(i-j));
                }
            }
        }

        return (ans==INT_MAX ? -1 : ans);
    }
};