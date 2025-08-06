class Solution {
public:
   //handling visited elements
    unordered_set<int>st;
    void solve(vector<int>&temp,vector<int>&nums,vector<vector<int>>&result){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            //preventing from copying same element
             if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(temp,nums,result);
                st.erase(nums[i]);
                temp.pop_back();
             }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>result;
        solve(temp,nums,result);
        return result;
    }
};