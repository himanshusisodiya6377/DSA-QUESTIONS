class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
          int grp = 0;
        int n = hand.size();
        unordered_map<int, int> mp;
        for (auto it : hand) {
            mp[it]++;
        }
        sort(hand.begin(), hand.end());
        int i = 0;
        while (i < n) {
            int g = groupSize;
            int num = hand[i];
            g--;
            if (mp.find(num) != mp.end()) {
                mp[num]--;
                if (mp[num] == 0)
                    mp.erase(num);
            } else {
                i++;
                continue;
            }
            while (g--) {
                num++;
                if (mp.find(num) != mp.end()) {
                    mp[num]--;
                    if (mp[num] == 0)
                        mp.erase(num);
                } else
                    return false;
            }
            grp++;
        }
        if (grp == (n / groupSize))
            return true;
        return false;
    }
};