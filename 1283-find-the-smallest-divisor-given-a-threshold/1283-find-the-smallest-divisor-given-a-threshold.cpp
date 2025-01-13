class Solution {
public:
int sum(vector<int>&v,int n){
        int sumi=0;
        for(int i=0;i<v.size();i++){
            sumi+=(ceil(1.0*v[i]/n));
        }
        return sumi;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=nums[n-1];
        int lo=1,hi=maxi;
        int mid;
        int mini=INT_MAX;
        while(lo<=hi){
            mid=(lo+hi)/2;
            int x=sum(nums,mid);
            if(x<=threshold) mini=mid;
            if(x<=threshold) hi=mid-1;
            else lo=mid+1;
        }
        return mini;
    }
};