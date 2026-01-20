class Solution {
public:
    int check(int n){
        int temp=n;
        
        int i=0;

        // string s=to_string(n);
        int len=ceil(log2(n));

        int mini=INT_MAX;
        while(i<len){
           temp=n;

           temp = temp ^ (1 << i);

        //    if(temp==n) break;

           if((temp | (temp+1))==n){
            mini=min(mini,temp);
           }

           i++;
        }

        return mini;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans[i]=-1;
            }
            else{
                ans[i]=check(nums[i]);
            }
        }
        return ans;
    }
};