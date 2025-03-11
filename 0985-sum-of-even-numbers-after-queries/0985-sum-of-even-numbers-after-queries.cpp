class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) sum+=nums[i];
        }
        vector<int>ans;
        int r=queries.size();
        for(int i=0;i<r;i++){
                if(nums[queries[i][1]]%2==0){
                    sum-=nums[queries[i][1]];
                    nums[queries[i][1]]+=(queries[i][0]);
                    if(nums[queries[i][1]]%2==0){
                        sum+=nums[queries[i][1]];
                    }
                }
                else{
                    nums[queries[i][1]]+=(queries[i][0]);
                    if(nums[queries[i][1]]%2==0)
                     sum+=nums[queries[i][1]];
                }
                ans.push_back(sum);
        }
        return ans;
    }
};