class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(auto &it : nums) sum+=it;
        
        bool flag=false;
        int idx=1;

        for(int i=0;i<n;i++){
           if(nums[i]%2!=0) flag=!flag;
           if(i==(6*idx-1)){
            flag=!flag;
            idx++;
           }
           
           if(flag) sum-=2*nums[i];
        //    cout<<sum<<" "<<flag<<endl;
        }

        return sum;
    }
};