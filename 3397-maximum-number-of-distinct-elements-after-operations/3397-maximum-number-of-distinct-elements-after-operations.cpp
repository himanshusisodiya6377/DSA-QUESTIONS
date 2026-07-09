class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        int offset=INT_MIN;

        unordered_set<int>st;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            
            int val=nums[i]-k;
            
            if(val>=offset){
                offset=val+1;
                st.insert(val);
            }
            else{
                //val<offset
                if(offset<=(nums[i]+k)){
                    st.insert(offset);
                    offset=offset+1;
                }
                else st.insert(nums[i]);
            }
            // cout<<val<<" "<<offset<<endl;
        }

        return st.size();
    }
};