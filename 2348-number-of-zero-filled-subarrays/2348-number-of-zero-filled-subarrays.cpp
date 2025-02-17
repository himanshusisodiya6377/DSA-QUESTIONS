class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
     int n=nums.size();
     vector<int>v;
     int count=0;
     for(int i=0;i<n;i++){
        if(nums[i]==0) {
            count++;
        }
        else{
            v.push_back(count);
            count=0;
        }
     }   
     v.push_back(count);
     int sum=0;
     for(int i=0;i<v.size();i++){
        if(v[i]!=0){
          sum+=((v[i]*(v[i]+1))/2);
        }
        
     }
     return sum;
    }
};