class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v(n,-1);
        if(k>n) return v;
        if(k==0) return nums;
        int slidsum=0;
        for(int i=0;i<2*k+1;i++){
            slidsum+=nums[i];
        }
        int num=2*k+1;
        int i=0,j=2*k,m=k;
        v[m]=slidsum/num;
        while(j<n-1){
            i++;
            j++;
            m++;
            slidsum=slidsum+nums[j]-nums[i-1];
            v[m]=slidsum/num;
        }
        return v;
    }
};