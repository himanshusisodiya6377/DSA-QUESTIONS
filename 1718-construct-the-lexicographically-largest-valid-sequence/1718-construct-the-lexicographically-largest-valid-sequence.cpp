class Solution {
public:
    bool solve(vector<int>&ans,int n,int idx,vector<bool>&visit){
        if(idx>=ans.size()) return true;
        
        if(ans[idx]!=0) return solve(ans,n,idx+1,visit);
        
        for(int i=n;i>0;i--){
            if(visit[i]) continue;
            if(i==1 || ((i+idx)<ans.size() && ans[idx+i]==0)){
                ans[idx]=i;
                visit[i]=true;
                if(i!=1) ans[idx+i]=i;
                if(solve(ans,n,idx+1,visit)) return true;
                ans[idx]=0;
                visit[i]=false;
                if(i!=1) ans[idx+i]=0;
            } 
        }

        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>ans(2*n-1,0);
        vector<bool>visit(n,false);
        solve(ans,n,0,visit);
        return ans;
    }
};