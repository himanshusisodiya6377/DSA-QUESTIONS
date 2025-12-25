class Solution {
public:
    typedef pair<int, int> p;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[0];
        int len = INT_MIN;
        int i = 0, j = 0;
        deque<p> ma;
        deque<p> mi;
        while (j < n) {
            
            while(!ma.empty() && ma.back().first<nums[j]) ma.pop_back();
            ma.push_back({nums[j], j});

            while(!mi.empty() && mi.back().first>nums[j]) mi.pop_back();
            mi.push_back({nums[j], j});
        
            while (i <= j && ma.front().first - mi.front().first > limit) {
                i++;
                while (!mi.empty() && i > mi.front().second) {
                    mi.pop_front();
                }
                while (!ma.empty() && i > ma.front().second) {
                    ma.pop_front();
                }
            }
            len = max(len, j - i + 1);
            j++;
        }
        return len;
    }
};