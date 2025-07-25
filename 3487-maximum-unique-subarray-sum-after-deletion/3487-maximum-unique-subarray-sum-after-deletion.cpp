class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++) st.insert(nums[i]);
        int sum=0;
        for(auto v : st){
            if(v>=0) sum+=v;
        }

        if(sum==0){
            int maxi=INT_MIN;
            for(auto v : st){
                maxi=max(maxi,v);
            }
            sum=maxi;
        }
        return sum;
    }
};