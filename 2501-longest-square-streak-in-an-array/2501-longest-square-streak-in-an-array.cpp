class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
     unordered_set<int>st;
     for(auto i : nums) st.insert(i);
     long long int maxi=INT_MIN;
     for(int i=0;i<nums.size();i++){
        if(nums[i]>=10000) continue;
        long long int sq=(long long)nums[i]*nums[i];
        int count=1;
        while(st.find(sq)!=st.end()){
            count++;
            sq=(long long)sq*sq;
        }     
        if(count>maxi) maxi=count;
        }  
        if(maxi<2) return -1; 
  return maxi;
    }
};