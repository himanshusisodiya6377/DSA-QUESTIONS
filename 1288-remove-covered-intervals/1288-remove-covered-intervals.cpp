class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int num=0;
        for(int i=0;i<n-1;i++){
            if(intervals[i][0]>=intervals[i+1][0] && intervals[i][1]<=intervals[i+1][1]){
                num++;
                intervals[i+1][0]=max(intervals[i][0],intervals[i+1][0]);
                intervals[i+1][1]=min(intervals[i][1],intervals[i+1][1]);
            }
            else if(intervals[i+1][0]>=intervals[i][0] && intervals[i+1][1]<=intervals[i][1]){
                num++;
                intervals[i+1][0]=max(intervals[i][0],intervals[i+1][0]);
                intervals[i+1][1]=min(intervals[i][1],intervals[i+1][1]);
            }
        }
        return n-num;
    }
};