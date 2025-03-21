class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1) return nums;
        vector<int>v(n-k+1,-1);
        int idx=-1;
        for(int i=0;i<k-1;i++){
            if((nums[i]+1)!=nums[i+1]) idx=i;
        }
        int m=0;
        if(idx==-1) v[m]=nums[k-1];
        m++;
        int i=1,j=k;
        while(j<n){
            if(idx>=i && idx<=j){
                if(nums[j]!=(nums[j-1]+1)) idx=j-1;
                i++;
                j++;
                m++;
              
                continue;
            }
            if(nums[j]==(nums[j-1]+1)){
                v[m]=nums[j];
                m++;
                j++;
                i++;
            } 
            else{
                idx=j-1;
                m++;
                i++;
                j++;
            }
        }
        return v;
    }
};