class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        
        int n=s.length();
        unordered_set<string>st;

        for(int i=0;i<(1<<n);i++){
            //let make the respective bit character capital
            int idx=0;
            string temp=s;
            int t=i;
            int len=n;
            while(len--){
                // cout<<i<<endl;
                if(t&1){
                    temp[n-1-idx]=toupper(temp[n-1-idx]);
                }
                else temp[n-1-idx]=tolower(temp[n-1-idx]);
                t>>=1;
                idx++;
            }
            // cout<<temp<<endl;
            st.insert(temp);
        }

        vector<string>ans;

        for(auto & it : st) ans.push_back(it);
        return ans;
    }
};