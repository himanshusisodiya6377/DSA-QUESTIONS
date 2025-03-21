class Solution {
public:
    int minSwaps(vector<int>& nums) {
     int n=nums.size();
     int k=0; //window size
     for(int i=0;i<n;i++){
        if(nums[i]==1) k++;
     }
    nums.insert(nums.end(), nums.begin(), nums.end());
     int mini=INT_MAX;
     int zero=0;
     for(int i=0;i<k;i++){
       if(nums[i]==0) zero++;
     }
     mini=zero;
     int i=0,j=k-1;
     while(i<n){
        i++;
        j++;
        if(nums[i-1]==0) zero--;
        if(nums[j]==0) zero++;
        mini=min(mini,zero); 
     }
     return mini;
    }
};