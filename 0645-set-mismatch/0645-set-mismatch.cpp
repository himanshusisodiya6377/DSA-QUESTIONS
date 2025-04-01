class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1,0);
        for (int i = 0; i < n; i++) {
           v[nums[i]]++;
        }
        vector<int>ans;
        int zero,twice;
        for(int i=1;i<n+1;i++){
            if(v[i]==0) zero=i;
            if(v[i]==2) twice=i;
        }
        ans.push_back(twice);
        ans.push_back(zero);
        return ans;
    }
};