class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            if (a.size() != b.size())
                return a.size() < b.size(); // smaller length first
            return a < b;                   // lexicographical compare
        });

        return nums[n-(k)];
    }
};