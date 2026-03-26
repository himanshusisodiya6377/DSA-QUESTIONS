class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int cnt_0 = 0, cnt_1 = 0;

        int i = 0, j = 0;
        int idx = -1;
        int ans = 0;
        while (j < n) {

            (s[j] == '0' ? cnt_0++ : cnt_1++);

            if (idx == -1)
                idx = j;
            else if (s[j - 1] != s[j])
                idx = j;

            if (cnt_0 != 0 && cnt_1 != 0 && cnt_0 == cnt_1) {
                ans += cnt_0;
                i = idx;
                (s[i - 1] == '0' ? cnt_0 = 0 : cnt_1 = 0);
            } else if (cnt_0 != 0 && cnt_1 != 0) {
                if (j < n - 1) {
                    if (s[j] != s[j + 1]) {
                        ans+=min(cnt_0,cnt_1);
                        i = idx;
                        if (s[i - 1] == '0')
                            cnt_0 = 0;
                        else
                            cnt_1 = 0;
                    }
                }
            }
            j++;
        }

        // if (cnt_0 == cnt_1)
            ans += min(cnt_0,cnt_1);

        return ans;
    }
};