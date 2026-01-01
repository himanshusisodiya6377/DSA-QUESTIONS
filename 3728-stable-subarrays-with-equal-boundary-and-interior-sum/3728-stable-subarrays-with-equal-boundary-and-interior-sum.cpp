class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n=capacity.size();
        unordered_map<long long,unordered_map<long long,long long>>mp;
        long long ans=0;
        long long pre=0;
        for(int i=0;i<n;i++){
           ans+=mp[capacity[i]][pre-capacity[i]];
           pre+=capacity[i];
           mp[capacity[i]][pre]++;
           if(i>0 && capacity[i]==0 && capacity[i-1]==0) ans--;
        }
        return ans;
    }
};