class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
       int p=0,N=1;
       vector<int>v(n);
       for(int i=0;i<n;i++){
        if(nums[i]>0 ){
            v[p]=nums[i];
            p+=2;
        }
        else if(nums[i]<0 ){
            v[N]=nums[i];
            N+=2;
        }
       }
       return v;
    }
};