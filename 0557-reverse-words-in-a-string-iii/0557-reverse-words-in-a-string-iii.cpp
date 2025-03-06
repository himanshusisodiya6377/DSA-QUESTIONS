class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, j = 0, k = 0;
        while (j < n) {
            if (s[j]==' ') {
                k = j - 1;
                while (i < k) {
                    swap(s[i], s[k]);
                    i++;
                    k--;
                }
                i = j + 1;
                k = i;
                j++;
            } else
                j++;
        }
                 k = j - 1;
                while (i < k) {
                    swap(s[i], s[k]);
                    i++;
                    k--;
                }
        return s;
    }
};