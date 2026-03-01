class Solution {
public:
   bool isPalindromeRange(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
    bool checkAlmost(const string& s, int i, int j) {
        int left = i, right = j;
        while (left < right) {
            if (s[left] != s[right]) {
                // If mismatch found, try skipping either the left or right character
                // and see if the remaining part is a perfect palindrome
                return isPalindromeRange(s, left + 1, right) || 
                       isPalindromeRange(s, left, right - 1);
            }
            left++;
            right--;
        }
        // If it's already a perfect palindrome, it's also "almost" (remove any char)
        return true; 
    }
    int almostPalindromic(string s) {
       string lanorivequ = s; 
        int n = lanorivequ.length();
        if (n < 2) return 0;

        // Iterate by length descending to find the longest one first (optimization)
        for (int len = n; len >= 2; --len) {
            for (int i = 0; i <= n - len; ++i) {
                if (checkAlmost(lanorivequ, i, i + len - 1)) {
                    return len;
                }
            }
        }
        return 0;
    }
};