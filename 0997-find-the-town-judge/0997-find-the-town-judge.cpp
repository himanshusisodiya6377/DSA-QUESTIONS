class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>ms;
        unordered_map<int,int>mf;
        int k=trust.size();
        if(k==0){
            if(n==1) return n;
            else return -1;
        }
        for(int i=0;i<k;i++){
            ms[trust[i][1]]++;
            mf[trust[i][0]]++;
        }
      int check=0;
        for(auto p: ms){
            if(p.second==n-1) check=p.first;
        }
       
            if(mf.find(check)==mf.end() && check!=0){
               return check;
            }
        
       return -1;
    }
};