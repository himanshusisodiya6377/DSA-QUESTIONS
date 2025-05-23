class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int>st;
        for(auto v: nums){
            st.insert(v);
        }
        int length=0;
        vector<int>ans;
        for(auto v :st){
           ans.push_back(v);
        }
        int maxi=INT_MIN;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]+1==ans[i+1]){
                length++;
               
            }
            else{
                 maxi=max(maxi,length);
                 length=0;
            }
        }
         maxi=max(maxi,length);
        return maxi+1;
    }
};