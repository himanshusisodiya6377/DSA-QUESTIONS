class Solution {
public:
    int rev(int num){
        int ans=0;
        while(num>0){
            int x=num%10;
            ans+=x;
            ans*=10;
            num/=10;
        }
      return ans/10;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        int m=1000000007;
        for(int i=0;i<n;i++){
            nums[i]-=rev(nums[i]);
        }
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+mp[nums[i]])%m;
             mp[nums[i]]++;
        }
        // int count=0;
        // for(auto p : mp){
        //     int x=p.second;
        //     count+=(x*(x-1)/2);
        // }

        return ans;
    }
};