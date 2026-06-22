class Solution {
public:
    bool check(string &a,string &b){
        int i=0,j=0;

        while(i<a.length() && j<b.length()){
            if(a[i]==b[j]){
                i++;
            }
            j++;
        }

        return i>=a.length();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        int n=dictionary.size();
       sort(dictionary.begin(), dictionary.end(),
    [](const string& a, const string& b){

        if(a.size() != b.size())
            return a.size() < b.size();

        return a < b;
    });

        // priority_queue<string,vector<string>,greater<string>>pq;
        vector<string>ans;

        for(auto &it : dictionary){
            if(check(it,s)) ans.push_back(it);
        }
        
        // for(auto &it : ans) cout<<it<<" ";
        while(ans.size()>1){
            if(ans[ans.size()-1].length() == ans[ans.size()-2].length()) ans.pop_back();
            else break;
        }
        return ans.empty() ? "" : ans.back();
    }
};