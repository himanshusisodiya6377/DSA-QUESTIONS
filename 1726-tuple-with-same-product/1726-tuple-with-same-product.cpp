class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,set<pair<int,int>>>mp;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]].insert({i,j});
            }
        }

        int ans=0;
        for(auto &it : mp){
            int sz=it.second.size();
            ans+=((sz)*(sz-1))/2;
        }
        return ans*8;
    }
};