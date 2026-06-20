class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]==0) continue;
            for(int j=i+1;j<n-1;j++){
                if(nums[j]==0) continue;
               auto it=lower_bound(nums.begin(),nums.end(),nums[i]+nums[j])-nums.begin();
               it--;
            //    if(it!=nums.end() && *it!=(nums[i]+nums[j]) ) {
            //     cout<<nums[i]<<" "<<nums[j]<<" "<<*it<<endl;
            //     ans++;
            //    }
            ans+=(it-j);
            }
        }
        return ans;
    }
};