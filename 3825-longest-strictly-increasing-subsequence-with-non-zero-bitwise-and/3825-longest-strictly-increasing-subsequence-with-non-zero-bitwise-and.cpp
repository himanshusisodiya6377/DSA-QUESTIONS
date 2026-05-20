class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

    vector<int> temp;

    for (int x : nums) {

        auto it = lower_bound(temp.begin(), temp.end(), x);

        if (it == temp.end())
            temp.push_back(x);
        else
            *it = x;
    }

    return temp.size();
     }
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int>>bit(31);

        for(int i=0;i<31;i++){
            for(auto &it : nums){
                if((it>>i) & 1){
                    bit[i].push_back(it);
                }
            }
        }

        // for(auto &it : bit){
        //     cout<<it.size()<<endl;
        // }
        int ans=0;
        for(auto &it : bit){
           ans=max(ans,lengthOfLIS(it));
        }
        return ans;
    }
};