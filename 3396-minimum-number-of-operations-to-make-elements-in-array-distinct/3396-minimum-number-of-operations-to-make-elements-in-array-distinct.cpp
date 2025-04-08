class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int maxi=0;
        for(auto v : mp){
            if(v.second.size()>1){
               int x=v.second.size();
               int diff=v.second[x-2]+1;
               int ceiling=ceil(diff/3.0);
               if(ceiling>maxi) maxi=ceiling;
            }
        }
        return maxi;
    }
};