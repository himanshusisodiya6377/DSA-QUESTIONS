class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        //basic sliding window
        //concept of min between both true and false
        int i = 0, j = 1;
        int maxi = INT_MIN;
        int countt = 0;
        int countf = 0;
        unordered_map<char,int>mp;
        mp[answerKey[0]]++;
        mp[answerKey[1]]++;
        // if (answerKey[0] == 'T')
        //     countt++;
        // else
        //     countf++;
        // if (answerKey[1] == 'T')
        //     countt++;
        // else
        //     countf++;
        while (j < n) {
            int mini = min(mp['T'],mp['F']);
            if (mini <= k) {
                j++;
                // if (answerKey[j] == 'T')
                //     countt++;
                // else
                //     countf++;
                mp[answerKey[j]]++;
            } else {
                int diff = j - i;
                maxi = max(maxi, diff);
                i++;
                // if (answerKey[i - 1] == 'T')
                //     countt--;
                // else
                //     countf--;
                mp[answerKey[i-1]]--;
            }
        }
        maxi = max(maxi, j - i);
        return maxi;
    }
};