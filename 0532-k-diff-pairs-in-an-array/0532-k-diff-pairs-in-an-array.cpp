class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();

        int i=0,j=1;
        int cnt=0;
        sort(nums.begin(),nums.end());

        while(j<n){

            //move i 
            while(i>0 && nums[i]==nums[i-1]) i++;

            if(j<=i) j=i+1;
            //move j till req diff is less
            while(j<n && nums[j]-nums[i]<k) j++;
            
            if(j<n && nums[j]-nums[i]==k){
                cnt++;
                i++;
                j++;
            }
            else i++;
        }

        return cnt;
    }
};