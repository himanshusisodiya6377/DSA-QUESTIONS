class Solution {
public:
    //did it but look for optimal appraoch 
    int tar;
    map<pair<vector<bool>,int>,bool>mp;
    bool solve(vector<int>&mat,int target,int sides,vector<bool>&visit){
        if(sides==1){
            return true;
        }
        // if(target<0) return false;
        if(mp.find({visit,sides})!=mp.end()) return mp[{visit,sides}];

        if(target==0){
            sides--;
            target=tar;
        }
        
        // cout<<sides<<" "<<target<<endl;
        // int sum=0;
        for(int i=0;i<mat.size();i++){
            if(!visit[i] && target-mat[i]>=0){
                visit[i]=true;
                if(solve(mat,target-mat[i],sides,visit)) return mp[{visit,sides}]=true;
                visit[i]=false;
            }
        }

        return mp[{visit,sides}]=false;
    }
    bool makesquare(vector<int>& mat) {
        // sort(mat.begin(),mat.end());
        int n=mat.size();
        int sum=0;
        for(auto &it : mat) sum+=it;
        if(sum%4!=0) return false;
        tar=sum/4;
        vector<bool>visit(n,false);
        return solve(mat,sum/4,4,visit);
    }
};