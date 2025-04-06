class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // sort(begin(nums1), end(nums1));
        // sort(begin(nums2), end(nums2));
        unordered_set<int> first;
        unordered_set<int> sec;
        for (int i = 0; i < n; i++)
            first.insert(nums1[i]);
        for (int i = 0; i < m; i++)
            sec.insert(nums2[i]);
        vector<vector<int>> ans;
        vector<int> fir;
        vector<int> se;
        for (int i = 0; i < n; i++) {
            // if (i != 0 && nums1[i] == nums1[i - 1])
            //     continue;
            if (sec.find(nums1[i]) == sec.end()) {
                fir.push_back(nums1[i]);
                sec.insert(nums1[i]);
            }
        }
        for (int i = 0; i < m; i++) {
            // if (i != 0 && nums2[i] == nums2[i - 1])
            //     continue;
            if (first.find(nums2[i]) == first.end()) {
                se.push_back(nums2[i]);
                first.insert(nums2[i]);
            }
        }
        ans.push_back(fir);
        ans.push_back(se);
        return ans;
    }
};