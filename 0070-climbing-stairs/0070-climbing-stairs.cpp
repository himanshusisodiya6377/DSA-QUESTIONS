class Solution {
public:
    int helper(unordered_map<int,int>&mp,int n){
        if(n==0 || n==1) return 1;
        if(mp.find(n)==mp.end()){
            mp[n]=helper(mp,n-1)+helper(mp,n-2);
        } 
        return mp[n];
    }
    int climbStairs(int n) {
        unordered_map<int,int>mp;
        return helper(mp,n);
    }
};