class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        for(auto &it : chunks) s+=it;

        cout<<s<<endl;
        int cnt=0;
        unordered_map<string,int>mp;

        string curr="";
        int n=s.length();

        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                mp[curr]++;
                curr="";
                cnt=0;
            }
            else if(s[i]=='-'){
                if(cnt==0 && i<n-1 && s[i+1]!='-' && curr!="" && s[i+1]!=' '){
                    curr.push_back('-');
                    cnt++;
                }
                else{
                    if(curr!=""){
                        mp[curr]++;
                        curr="";
                        cnt=0;
                    }
                }
            }
            else{
               curr.push_back(s[i]);
               cnt=0;
            }
        }

        if(curr!="") mp[curr]++;


        for(auto &it : mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        vector<int>ans(queries.size(),0);

        for(int i=0;i<queries.size();i++){
            ans[i]=mp[queries[i]];
        }
        return ans;
    }
};