class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto &it : nums) sum+=it;
        int avg=sum/n;

        // sort(nums.begin(),nums.end());
        // auto it=upper_bound(nums.begin(),nums.end(),avg);

        // if(it==nums.end()) return nums[n-1]+1;
        
        int ans=avg+1;
        unordered_set<int>st;
        for(auto &it : nums) st.insert(it);
        if(ans<=0) ans=1;
        while(1){
            if(st.count(ans)) ans++;
            else break;
        }
        return ans;   
    }
};