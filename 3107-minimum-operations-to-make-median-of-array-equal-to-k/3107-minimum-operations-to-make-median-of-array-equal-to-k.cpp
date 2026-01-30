class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n=nums.size();
        long long cnt=0;
        int gt=(n%2==0 ? (n/2)-1 : n/2);
        cout<<gt<<endl;
        sort(nums.begin(),nums.end());
        int i=n-1;
        int temp=gt;
        while(i>=0){
            //move till can tget graeetr or eqaul gt
            while(i>=0 && gt>0){
                if(nums[i]<k){
                  cnt+=(k-nums[i]);
                }
                i--;
                gt--;
            }
             cout<<i<<endl;
            if(i==(n-temp-1) && nums[i]<k){
                cnt+=abs(nums[i]-k);
            }

            //now we are at correct position
            //all in left has to be eqaul or small
            if(i>=0 && nums[i]>k) cnt+=nums[i]-k;
            i--;
        }

        return cnt;
    }
};