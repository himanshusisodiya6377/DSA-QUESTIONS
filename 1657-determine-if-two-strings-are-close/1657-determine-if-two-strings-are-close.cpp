class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (m != n)
            return false;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (int i = 0; i < n; i++)
            mp1[word1[i]]++;
        for (int i = 0; i < m; i++)
            mp2[word2[i]]++;
        vector<int> first;
        vector<int> second;
        vector<char> firs;
        vector<char> sec;
        for (auto p : mp1) {
            firs.push_back(p.first);
            first.push_back(p.second);
        }
        for (auto p : mp2) {
            sec.push_back(p.first);
            second.push_back(p.second);
        }
        sort(first.begin(), first.end());
        sort(firs.begin(), firs.end());
        sort(second.begin(), second.end());
        sort(sec.begin(), sec.end());
        if (first != second)
            return false;
        if (firs != sec)
            return false;
        return true;
        

        //we can also do this question with frequency approach
        // vector<int>first(26,0);
        // vector<int>sec(26,0);
        // for(int i=0;i<n;i++) first[word1[i]-97]++;
        // for(int i=0;i<m;i++) sec[word2[i]-97]++;
        // sort(first.begin(),first.end());
        // sort(sec.begin(),sec.end());
        // if(first!=sec) return false;
        // return true;
    }
};