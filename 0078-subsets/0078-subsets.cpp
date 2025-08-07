class Solution {
public:

//   unordered_set<int>st;
 
   void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,int idx){
       
      if(idx>nums.size()) return;

       ans.push_back(temp);

       for(int i=idx;i<nums.size();i++){
  
     
        
            temp.push_back(nums[i]);
            // st.insert(nums[i]);

            solve(nums,ans,temp,i+1);

            temp.pop_back();
            // st.erase(nums[i]);

        
       }

   }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,ans,temp,0);
        return ans;
    }
};