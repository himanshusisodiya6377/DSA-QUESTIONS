class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int count=0;
        for(auto p : mp){
            int x=(p.second).size();
            count+=((x*(x-1))/2);
        }
        return count;
    }
};