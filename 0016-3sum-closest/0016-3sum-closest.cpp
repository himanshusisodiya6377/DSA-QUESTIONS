class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();

        int ans=INT_MAX;
        int sol=0;
        
        sort(nums.begin(),nums.end());

        for(int k=0;k<n;k++){
           int i=k+1,j=n-1;
           while(i<j){
           int sum=nums[k]+nums[i]+nums[j];
           int diff=abs(target-sum);

           if(diff<ans){
            ans=diff;
            sol=sum;
            // cout<<nums[k]<<" "<<nums[i]<<" "<<nums[j]<<endl;
           }
            
            if(sum<=target) i++;
            else j--;
           }
        }

        return sol;
    }
};