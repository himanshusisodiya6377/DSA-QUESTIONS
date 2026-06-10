class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;

        unordered_map<string,vector<int>>mp;

        for(auto &it : words1){
            vector<int>v(26,0);
            for(auto &x : it){
                v[x-'a']++;
            }
            mp[it]=v;
        }

        vector<int>temp(26,0);
        for(auto &it : words2){
            vector<int>t(26,0);
            for(auto &x : it){
                t[x-'a']++;
            }
            for(int i=0;i<26;i++){
                temp[i]=max(temp[i],t[i]);
            }
        }

        // for(auto &it : temp) cout<<it<<" ";
        // cout<<endl; 
        // for(auto &it : mp){
        //     cout<<it.first<<" ";
        //     cout<<endl;
        //     for(auto &x  :it.second) cout<<x<<" ";
        //     cout<<endl;
        // }

        for(auto &it : mp){
            bool flag=true;
            for(int i=0;i<temp.size();i++){
                if(temp[i]!=0 && temp[i]>it.second[i]){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(it.first);
        }

        return ans;
    }
};