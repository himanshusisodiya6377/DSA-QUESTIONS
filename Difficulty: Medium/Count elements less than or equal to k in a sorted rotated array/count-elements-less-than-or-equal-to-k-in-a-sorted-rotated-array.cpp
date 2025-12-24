class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();

      
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] <= arr[hi])
                hi = mid;
            else
                lo = mid + 1;
        }
        int pivot = lo;

       
        int cnt1 = upper_bound(arr.begin(), arr.begin() + pivot, x) - arr.begin();

        
        int cnt2 = upper_bound(arr.begin() + pivot, arr.end(), x) - (arr.begin() + pivot);

        return cnt1 + cnt2;
    }
};
