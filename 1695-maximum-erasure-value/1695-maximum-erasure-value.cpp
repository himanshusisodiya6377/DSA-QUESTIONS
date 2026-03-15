class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();

        vector<int>pre(n,0);
        pre[0]=nums[0];

        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];

        int i=0,j=0;
        
        unordered_set<int>st;
        long long ans=0;
        while(j<n){
          

          while(i<=j  && st.find(nums[j])!=st.end()){
            st.erase(nums[i]);
            i++;
          }
          st.insert(nums[j]);
          
          long long sum=pre[j]-(i>0 ? pre[i-1] : 0);
          
          ans=max(ans,sum);
          j++;
        }

        return ans;
    }
};