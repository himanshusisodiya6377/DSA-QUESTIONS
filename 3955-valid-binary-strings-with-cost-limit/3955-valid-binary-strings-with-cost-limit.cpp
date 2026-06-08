class Solution {
public:
    vector<string>ans;
    void solve(int idx,int n,int k,int cost,string s,bool flag){
        if(idx>=n){
            if(cost<=k) ans.push_back(s);
            return;
        }

        if(cost>k) return;

        //bool --> true last is zero
        if(!flag){
            s+="1";
            cost+=idx;
            solve(idx+1,n,k,cost,s,true);
            s.pop_back();
            cost-=idx;
        }
        s+="0";
        solve(idx+1,n,k,cost,s,false);
        s.pop_back();
        
    }
    vector<string> generateValidStrings(int n, int k) {
       solve(0,n,k,0,"",false);
       return ans;        
    }
};