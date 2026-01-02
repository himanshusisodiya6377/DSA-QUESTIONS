class Solution {
public:
     //sort the array and get the possible largest window which satisfy consition
     //here we are looking for valid not looking for those to be change 
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>st(nums.begin(),nums.end());
        vector<int>v(st.begin(),st.end());

        int n=nums.size();
        int ans=n;
        int j=0;

        for(int i=0;i<v.size();i++){
             while(j<v.size() && v[j]<v[i]+n) j++;
             ans=min(ans,n-(j-i));
        }
        return ans;
    }
};