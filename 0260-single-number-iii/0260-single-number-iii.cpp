class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long  n=nums.size();

        long long  xr=0;
        for(auto &it : nums) xr^=it;

        long long buckA=0;
        long long  buckB=0;

        long long rbit=xr & (-xr);

        for(auto &it : nums){
            if((it & rbit)==0) buckA^=it;
            else buckB^=it;
        }

        return {(int)buckA,(int)buckB};
    }
};