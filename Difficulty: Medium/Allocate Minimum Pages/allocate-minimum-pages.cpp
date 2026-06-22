class Solution {
public:

    bool check(vector<int>& arr, int mid, int k) {

        int students = 1;
        int pages = 0;

        for(int x : arr) {

            if(pages + x <= mid) {
                pages += x;
            }
            else {
                students++;
                pages = x;
            }
        }

        return students <= k;
    }

    int findPages(vector<int> &arr, int k) {

        int n = arr.size();

        if(k > n) return -1;

        int lo = *max_element(arr.begin(), arr.end());
        int hi = accumulate(arr.begin(), arr.end(), 0);

        int ans = -1;

        while(lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if(check(arr, mid, k)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};