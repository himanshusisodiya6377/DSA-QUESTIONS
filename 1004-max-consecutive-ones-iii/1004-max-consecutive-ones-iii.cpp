class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int idx=-1;
        int cnt=0;
        
        if(k==0){
            int len=0;
            int m=0;
            for(int i=0;i<n;i++){
                if(nums[i]==1){
                    len++;
                    m=max(m,len);
                }
                else len=0;
            }
            m=max(m,len);
            return m;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }
            if(cnt<=k){
                idx=i;
                // break;
            }
        }
        
        // cout<<idx<<endl;
        
        cnt=k;
        int i=0,j=idx;
        int maxi=idx-i+1;
        while(j<n){
            while(i<n && nums[i]==1){
                i++;
            }
            i++;
            cnt--;
            j++;
            if(j<n && nums[j]==0) cnt++;
            while(j<n && nums[j]==1){
                j++;
                // if(nums[j]==0) cnt++;
            }
            // cnt++;
        
            if(j<n-1 && nums[j+1]==1){
              while(j<n-1 && nums[j+1]==1) j++;
            }
            // j--;

            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};