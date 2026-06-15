class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();

        priority_queue<int>pq;
        for(auto &it : nums) pq.push(it);

        int ans=0;
        sort(nums.begin(),nums.end());

        for(int i=n-1;i>=0;i--){
            if(pq.empty()) break;
            while(!pq.empty() && pq.top()>=nums[i]) pq.pop();
            if(!pq.empty()) {
                ans++;
                pq.pop();
            }      
        }

        return ans;

    }
};