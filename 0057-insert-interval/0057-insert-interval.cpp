class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int i=0,j=1;
        vector<int>temp;
        temp=intervals[i];
        vector<vector<int>>ans;
        while(j<intervals.size()){
            if(intervals[j][0]<=temp[1]){
                temp[0]=intervals[i][0];
                if(intervals[j][1]<=temp[1]){
                    // temp[1]=(intervals[i][1]);
                    // ans.push_back(temp);
                    // temp.clear();
                    j++;
                    // i=j;
                    // j++;
                    // temp=intervals[i];
                }
                else if(intervals[j][1]>temp[1]){
                    temp[1]=intervals[j][1];
                    // ans.push_back(temp);
                    // i=j;
                    j++;
                    // temp=intervals[i];
                }
                // else if()
                else{
                    // temp[1]=intervals[j][1];
                    ans.push_back(temp);
                    i=j;
                    j++;
                    temp=intervals[i];
                }
            }
            else{
                ans.push_back(temp);
                i=j;
                j++;
                temp=intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};