class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1=0;
        int maxi1=0;
        int count2=0;
        int maxi2=0;
       vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi1) count1++;
            else if(nums[i]==maxi2) count2++;
            else if(count1==0){
                maxi1=nums[i];
                count1=1;
            }
            else if(count2==0){
                maxi2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
      //first verification
      int count=0;
      for(int i=0;i<n;i++){
        if(nums[i]==maxi1) count++;
      }
      if(count>n/3) ans.push_back(maxi1);
      count=0;
       for(int i=0;i<n;i++){
        if(nums[i]==maxi2) count++;
      }
      if(count>n/3 && maxi1!=maxi2) ans.push_back(maxi2);
    return ans;
    }
};