class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.length();
        int m=s.length();

        vector<string>a;

        unordered_map<char,string>mp;
        unordered_set<string>st;

        stringstream ss(s);

        string word;
        while (ss >> word) { 
         a.push_back(word);
        }

        if(n!=a.size()) return false;

        for(int i=0;i<n;i++){
            if(mp.find(pattern[i])!=mp.end() && mp[pattern[i]]!=a[i]){
                // cout<<"yes"<<endl;
              return false;
            }
            else if(st.count(a[i]) && (mp.find(pattern[i])==mp.end() && mp[pattern[i]]!=a[i])) {
                cout<<i<<endl;
                return false;
            }
            else{
               mp[pattern[i]]=a[i];
               st.insert(a[i]);
            }
        }

        return true;
    }
};