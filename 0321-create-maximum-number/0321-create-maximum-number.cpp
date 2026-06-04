class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans;

        for (int sz = max(0, k - m); sz <= min(k, n); sz++) {

            int rem = k - sz;

            deque<int> n1;
            int j = 0;

            while (j < n) {
                while (!n1.empty() &&
                       (n1.size() + (n - j)) > sz &&
                       n1.back() < nums1[j]) {
                    n1.pop_back();
                }

                n1.push_back(nums1[j]);
                j++;
            }

            while ((int)n1.size() > sz)
                n1.pop_back();

            deque<int> n2;
            j = 0;

            while (j < m) {
                while (!n2.empty() &&
                       (n2.size() + (m - j)) > rem &&
                       n2.back() < nums2[j]) {
                    n2.pop_back();
                }

                n2.push_back(nums2[j]);
                j++;
            }

            while ((int)n2.size() > rem)
                n2.pop_back();

            vector<int> v;
            j = 0;

            while (j < k) {

                if (!n1.empty() && !n2.empty()) {

                    auto it1 = n1.begin();
                    auto it2 = n2.begin();

                    while (it1 != n1.end() &&
                           it2 != n2.end() &&
                           *it1 == *it2) {
                        ++it1;
                        ++it2;
                    }

                    bool takeFirst;

                    if (it2 == n2.end())
                        takeFirst = true;
                    else if (it1 == n1.end())
                        takeFirst = false;
                    else
                        takeFirst = (*it1 > *it2);

                    if (takeFirst) {
                        v.push_back(n1.front());
                        n1.pop_front();
                    } else {
                        v.push_back(n2.front());
                        n2.pop_front();
                    }
                }
                else if (!n1.empty()) {
                    v.push_back(n1.front());
                    n1.pop_front();
                }
                else {
                    v.push_back(n2.front());
                    n2.pop_front();
                }

                j++;
            }

            if (ans.empty() || v > ans)
                ans = v;
        }

        return ans;
    }
};