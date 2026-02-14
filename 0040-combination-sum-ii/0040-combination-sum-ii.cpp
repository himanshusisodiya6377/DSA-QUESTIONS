class Solution {
public:
        vector<vector<int>>ans;
        void solve(vector<int>&can,int tar,int idx,int sum,vector<int>temp){
            if(sum>tar) return;

            if(sum==tar){
                ans.push_back(temp);
            }


            for(int i=idx;i<can.size();i++){
            if(i>idx && can[i]==can[i-1]) continue;
                temp.push_back(can[i]);
                sum+=can[i];
                solve(can,tar,i+1,sum,temp);
                temp.pop_back();
                sum-=can[i];
            }
        }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        vector<int>temp;
        sort(can.begin(),can.end());
        solve(can,tar,0,0,temp);
        return ans;
    }
};