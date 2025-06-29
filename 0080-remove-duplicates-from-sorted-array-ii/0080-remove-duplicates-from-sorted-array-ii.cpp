class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]=3) mp[nums[i]]--;
        }
        int i=0,j=0;
        while(i<n && j<n){
            if(mp.find(nums[j])!=mp.end()){
                mp[nums[j]]--;
                if(mp[nums[j]]==0) mp.erase(nums[j]);
                swap(nums[i],nums[j]);
                i++;
                j++;           
            }
            else j++;
        }
   return i;
    }

};