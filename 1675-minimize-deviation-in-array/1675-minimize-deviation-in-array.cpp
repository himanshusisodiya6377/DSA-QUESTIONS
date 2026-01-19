class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        
        int ans=INT_MAX;

        int min_val=INT_MAX;
        priority_queue<int>pq; //max heap

        for(auto &it : nums){
            if(it%2==0) pq.push(it);
            else {
                it=2*it;
                pq.push(it);
            }
            min_val=min(min_val,it);
        }

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();

            ans=min(ans,p-min_val);
            if(p%2==1) break;
           
            p/=2;
           
            pq.push(p);
            min_val=min(min_val,p);
        }

        return ans;
    }
};