class Solution {
public:
    int solve(vector<int>&nums,unordered_map<int,int>&st,int k,int idx){
        if(idx>=nums.size()) return 1;

        //include it
        int inc=INT_MIN;
        if(st.find(nums[idx]-k)==st.end()){
            st[nums[idx]]++;
            inc=solve(nums,st,k,idx+1);
            st[nums[idx]]--;
            if(st[nums[idx]]==0) st.erase(nums[idx]);
        }
        // unordered_set<int>temp;
        int not_inc=solve(nums,st,k,idx+1);
        
        // temp.insert(nums[idx]);
        // int start=solve(nums,temp,k,idx+1);
        // temp.erase(nums[idx]);
        return (inc==INT_MIN ? not_inc : not_inc+inc);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>st;
        return solve(nums,st,k,0)-1;
    }
};