class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
     int n=nums.size();
    //  //TC O(n) //SC O(n)
    //  vector<int>v;
    //  int count=0;
    //  for(int i=0;i<n;i++){
    //     if(nums[i]==0) {
    //         count++;
    //     }
    //     else{
    //         v.push_back(count);
    //         count=0;
    //     }
    //  }   
    //  v.push_back(count);
    //  long long sum=0;
    //  for(int i=0;i<v.size();i++){
    //     if(v[i]!=0){
    //         long long prod=(long long)v[i]*(v[i]+1);
    //       sum+=(prod/2);
    //     }
        
    //  }
    //  return sum;
    //2nd approach
    int count=0;
    vector<int>pre(n,0);
    for(int i=0;i<n;i++){
    if(nums[i]==0){
        count++;
        pre[i]=count;
    }
    else{
        count=0;
        pre[i]=0;
    }
    }
    long long  sum=0;
    for(int i=0;i<n;i++){
        sum+=pre[i];
    }
    return sum;
    }
};