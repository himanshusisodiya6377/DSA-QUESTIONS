class Solution {
public:
    bool prime(int n){
        if(n==1) return false;
        if(n==2) return true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto v : mp){
            if(prime(v.second)){
                return true;
            }
        }
      return false;
    }
};