class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int r=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<r-1;i++){
            if(intervals[i+1][0]<=intervals[i][1] && intervals[i+1][0]>=intervals[i][0]){
                intervals[i+1][0]=min(intervals[i+1][0],intervals[i][0]);
                intervals[i+1][1]=max(intervals[i+1][1],intervals[i][1]);
            }
            else{
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        ans.push_back({intervals[r-1][0],intervals[r-1][1]});
       return ans;
    }
};