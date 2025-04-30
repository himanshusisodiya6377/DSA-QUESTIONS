class Solution {
public:
    bool check(int n){
        int count=0;
        while(n>0){
            count++;
            n/=10;
        }
        if(count%2==0) return true;
        else return false;
    }
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(check(nums[i])) ans++;
        }
        return ans;
    }
};