class Solution {
public:
void toggle(vector<int>&nums,int i,int n){
    int k=3;
    if(i+2>=n) return;
    while(k){
        if(nums[i]==0) nums[i]=1;
        else nums[i]=0;
        k--;
        i++;
    }
}
    int minOperations(vector<int>& nums) {
     int n=nums.size();
     int count=0;
     for(int i=0;i<n;i++){
        if(nums[i]==0){
            toggle(nums,i,n);
            count++;
        }
     }   
     for(int i=0;i<n;i++){
        if(nums[i]==0) return -1;
     }
     return count;
    }
};