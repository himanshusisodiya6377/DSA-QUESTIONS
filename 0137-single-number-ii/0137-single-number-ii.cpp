class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_set<int>st;
        int n=nums.size();
        // long long sum=0;
        // for(auto i : nums){
        //     st.insert(i);
        //     sum+=i;
        // }
        // long long setsum=0;
        // for(auto p : st){
        //     setsum+=p;
        // }
        // sum-=setsum;
        // sum/=2;
        // setsum-=sum;
        // return setsum;


        // unordered_map<int,int>mp;
        // for(auto i : nums) mp[i]++;
        // for(auto p : mp){
        //     if(p.second==1) return p.first;
        // }
        // return -1;

          sort(begin(nums),end(nums));
          if(n==1) return nums[0];
          if(nums[0]!=nums[1]) return nums[0];
          int i=1;
          while(i<n-1){
            if(nums[i]==nums[i+1] && nums[i]==nums[i-1]){
                i+=3;
            }
            else if(nums[i]==nums[i+1] && nums[i]!=nums[i-1]) return nums[i-1];
            else if(nums[i]!=nums[i+1] && nums[i]==nums[i-1]) return nums[i+1];
            else return nums[i];
          }
          if(nums[n-1]!=nums[n-2]) return nums[n-1]; 
          return -1;
    }
};