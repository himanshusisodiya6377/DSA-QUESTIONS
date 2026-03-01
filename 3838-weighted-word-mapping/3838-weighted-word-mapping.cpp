class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto &it : words){
            int sum=0;
            for(auto &x : it){
                sum+=weights[x-'a'];
            }
            // cout<<sum%26;
            // cout<<sum<<endl;
            ans.push_back(('z'-sum%26));
        }
        return ans;
    }
};