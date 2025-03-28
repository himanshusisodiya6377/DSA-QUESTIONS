class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>ans;
        sort(begin(nums),end(nums));
        for(int i=0;i<m;i++){
            int sum=0;
            int j=0;
            while(j<n && sum + nums[j] <= queries[i]){
                sum+=nums[j];
                j++;
            }
            // if(j<n) sum-=nums[j];
            if(sum<=queries[i]) ans.push_back(j);
        }
        return ans;
    }  
};