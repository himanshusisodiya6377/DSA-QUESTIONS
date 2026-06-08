class Solution {
public:
    bool compare_string(string &s, string &t) {
        if (s.size() > t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) return false;
        }

        return true;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        int n=folder.size();

        // for(auto &it : folder){
        //     cout<<it<<" ";
        // }

        vector<string>ans;
        ans.push_back(folder[0]);

        for(int i=1;i<n;i++){
            string comp=ans.back();
            comp+="/";

            if(!compare_string(comp,folder[i])){
               ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};