class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int total_subset=pow(2,n);
        for(int i=0;i<total_subset;i++){
            int check=0;
            for(int j=0;j<n;j++){
                if((i & (1<<j))!=0){
                    check^=nums[j];
                }
            }
            ans+=check;
        }
    return ans;
    }
};