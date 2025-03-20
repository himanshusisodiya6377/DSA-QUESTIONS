class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_set<int>st;
        // int n=nums.size();
        // long long sum=0;
        // for(auto i : nums){
        //     st.insert(i);
        //     sum+=i;
        // }
        // long long setsum=0;
        // for(auto p : st){
        //     setsum+=p;
        // }
        // sum-=setsum;
        // sum/=2;
        // setsum-=sum;
        // return setsum;
        unordered_map<int,int>mp;
        for(auto i : nums) mp[i]++;
        for(auto p : mp){
            if(p.second==1) return p.first;
        }
        return -1;
    }
};