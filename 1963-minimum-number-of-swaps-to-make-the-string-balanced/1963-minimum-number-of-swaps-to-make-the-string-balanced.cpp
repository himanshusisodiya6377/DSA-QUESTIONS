class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        stack<char>st;
        int ans=0;
        int cnt=0;
        for(auto &it: s){
            if(it=='['){
                st.push(it);
            }
            else{
                if(st.size()>0) st.pop();
                else cnt++;
            }
            if(cnt>=2){
                ans++;
                cnt-=2;
            }
        }
        // if(st.size()==0 || st.size()==1) return st.size();
        if(cnt>=2){
            ans++;
            cnt-=2;
        }
        else ans+=cnt;
        return ans;
    }
};