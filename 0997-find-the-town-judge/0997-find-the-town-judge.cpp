class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //TC-O(n) //SC-O(n)
    //     unordered_map<int,int>ms;
    //     unordered_map<int,int>mf;
    //     int k=trust.size();
    //     if(k==0){
    //         if(n==1) return n;
    //         else return -1;
    //     }
    //     for(int i=0;i<k;i++){
    //         ms[trust[i][1]]++;
    //         mf[trust[i][0]]++;
    //     }
    //   int check=0;
    //     for(auto p: ms){
    //         if(p.second==n-1) check=p.first;
    //     }
       
    //         if(mf.find(check)==mf.end() && check!=0){
    //            return check;
    //         }
        
    //    return -1;
    //TC-O(n) //SC-O(1)
      vector<int> Trusted(n+ 1, 0);
        for(auto person : trust){
            Trusted[person[0]]--;
            Trusted[person[1]]++;
        }
        for(int i = 1;i <= n;i++){
            if(Trusted[i] == n - 1)
                return i;
        }
        return -1;
    }
};