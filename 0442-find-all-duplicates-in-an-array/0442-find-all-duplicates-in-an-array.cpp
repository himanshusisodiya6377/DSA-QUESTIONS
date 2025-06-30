class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    //  int n=nums.size();
    //  vector<int>v;
    //  int i=0;
    //  while(i<n){
    //     int coridx=nums[i]-1;
    //     if(nums[i]==(i+1)) i++;
    //     else {
    //         if(nums[i]==nums[coridx]) i++;
    //     else swap(nums[i],nums[coridx]);
    //     }
               
    //  }   
    //  for(int i=0;i<n;i++){
    //     if(nums[i]!=i+1){
    //         v.push_back(nums[i]);
    //     }
    //  }
    //  return v;
      int n=nums.size();
        int i=0;
        while(i<n){
            while(i<n && nums[i]==i+1) i++;
            while( i<n && nums[i]!=(i+1)){
            if(nums[i]==nums[nums[i]-1]){
                 i++;
                 break;
            }
            else swap(nums[i],nums[nums[i]-1]);
            }        
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=(i+1)) ans.push_back(nums[i]);
        }
        return ans;
    }
};