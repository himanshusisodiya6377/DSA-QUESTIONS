class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int grp=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n){
            int g=k;
            int num=nums[i];
            g--;
            if(mp.find(num)!=mp.end()){
            mp[num]--;
             if(mp[num]==0) mp.erase(num);
            }
            else {
                i++;
                continue;
            }
            while(g--){
               num++;
               if(mp.find(num)!=mp.end()){
                mp[num]--;
                if(mp[num]==0) mp.erase(num);
               }
               else return false;
            }
            grp++;
        }
        if(grp==(n/k)) return true;
        return false;
    }
};