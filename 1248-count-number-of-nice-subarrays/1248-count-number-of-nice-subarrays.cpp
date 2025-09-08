class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int idx=-1;
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0) cnt++;
            if(cnt==k){
                idx=i;
                break;
            }
        }
        if(idx==-1) return 0;
        int i=0,j=idx;
        int range=1;
        while(j<n){
            range=1;
            while(i<n && nums[i]%2==0){
                i++;
                range++;
            }
            i++;
            j++;
            cnt-=1;
            int r=1;
            while(j<n && nums[j]%2==0){
                r++;
                j++;
            }
            // j++;
            // while(j<n && cnt!=k){
            //     if(nums[j]%2!=0) cnt++;
            //     j++;
            // }
            ans+=range*r;
        }
        return ans;
    }
};