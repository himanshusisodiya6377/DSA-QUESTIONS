class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        //marking negative element to zero as we dont care about them
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]=0;
        }
        //marking element position by making it negative
        for(int i=0;i<n;i++){
            int cord=abs(nums[i])-1;
            if(cord<0 || cord>=n) continue;
            else if(nums[cord]<0) continue;
            else if(nums[cord]==0) nums[cord]=-(n+2);
            else nums[cord]*=(-1);
        }  

        //checking in range 1 to n+1
        for(int i=1;i<=n+1;i++){
           int cord=i-1;
           if(cord>=n) return i;
           else if(nums[cord]<0) continue;
           else return i;
        }

        return 0;
    }
};