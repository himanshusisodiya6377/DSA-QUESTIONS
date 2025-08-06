class Solution {
public:
    set<vector<int>>st;
    set<int>visit;

    void solve(vector<int>&nums,vector<int>&temp){
 
        if(temp.size()==nums.size()){
            st.insert(temp);
        }

        for(int i=0;i<nums.size();i++){
            if(visit.find(i)==visit.end()){
                visit.insert(i);
                temp.push_back(nums[i]);
                solve(nums,temp);
                visit.erase(i);
                temp.pop_back();
            }
        }

    }
 

    vector<vector<int>> permuteUnique(vector<int>& nums) {

    vector<vector<int>>ans;
    vector<int>temp;

    solve(nums,temp);

    for(auto it : st){
        ans.push_back(it);
    }
 
    return ans;
 
    }
};