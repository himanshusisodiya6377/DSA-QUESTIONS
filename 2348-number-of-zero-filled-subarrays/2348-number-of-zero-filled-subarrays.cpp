class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
     int n=nums.size();
    //  //TC O(n) //SC O(1)
     int c=0;
     long long sum=0;
     for(int i=0;i<n;i++){
        if(nums[i]==0) {
            c++;
        }
        else{
            sum+=(0.5*c*(c+1));
            c=0;
        }
     }   
     if(c>0)  sum+=(0.5*c*(c+1));
     return sum;
    //2nd approach
    //TC-O(N) SC-O(N)
    // int count=0;
    // vector<int>pre(n,0);
    // for(int i=0;i<n;i++){
    // if(nums[i]==0){
    //     count++;
    //     pre[i]=count;
    // }
    // else{
    //     count=0;
    //     pre[i]=0;
    // }
    // }
    // long long  sum=0;
    // for(int i=0;i<n;i++){
    //     sum+=pre[i];
    // }
    // return sum;
    }
};