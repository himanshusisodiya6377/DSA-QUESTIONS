class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int range=n/2+1;
        int target;
        int targetfreq;
        for(auto v : mp){
             if(v.second>=range){
                target=v.first;
                targetfreq=v.second;
                break;
             }
        }
        int countrange=0;
        for(int i=0;i<n;i++){
             if(nums[i]==target) countrange++;
             if(countrange>((i+1)/2) && (targetfreq-countrange)>((n-(i+1))/2)){
                return i;
             }
        }
    return -1;
    }
};