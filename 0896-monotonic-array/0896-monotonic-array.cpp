class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2) return true;
        else{
            vector<int>v=nums;
            sort(v.begin(),v.end());
            vector<int>vrev=v;
            reverse(vrev.begin(),vrev.end());
            if(nums==v) return true;
            if(nums==vrev) return true;
        }
        return false;
    }
};