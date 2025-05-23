class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        set<int> st;
        for (auto v : nums) {
            st.insert(v);
        }
        int length = 0;
        // vector<int>ans;
        int prev = INT_MIN;
        int maxi = INT_MIN;
        for (auto v : st) {
            if (prev == INT_MIN) {
                prev = v;
            } else {
                if (prev + 1 == v) {
                    length++;
                    prev=v;
                } else {
                    maxi = max(maxi, length);
                    length = 0;
                    prev=v;
                }
            }
        }

        // for(int i=0;i<ans.size()-1;i++){
        //     if(ans[i]+1==ans[i+1]){
        //         length++;

        //     }
        //     else{
        //          maxi=max(maxi,length);
        //          length=0;
        //     }
        // }
        maxi = max(maxi, length);
        return maxi + 1;
    }
};