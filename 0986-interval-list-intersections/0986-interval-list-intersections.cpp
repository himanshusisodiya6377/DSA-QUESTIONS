class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n=firstList.size();
        int m=secondList.size();
        if(n==0 || m==0) return {};
        int i=0,j=0;
        vector<vector<int>>ans;
        while(i<n && j<m){
            //no overlapping
            if(firstList[i][1]<secondList[j][0]){
               i++;
            }
            //small overlapping
            else if(firstList[i][1]>=secondList[j][0] && firstList[i][1]<=secondList[j][1]){
                int y=min(firstList[i][1],secondList[j][1]);
                int x=max(firstList[i][0],secondList[j][0]);
                ans.push_back({x,y});
                i++;
            }
            else if(secondList[j][1]>=firstList[i][0] && secondList[j][1]<=firstList[i][1]){
                int y=min(firstList[i][1],secondList[j][1]);
                int x=max(firstList[i][0],secondList[j][0]);
                ans.push_back({x,y});
                 j++;
            }
            else if(secondList[j][1]<firstList[i][0]){
                j++;
            }
            else{
                int x=min(firstList[i][1],secondList[j][1]);
                int y=max(firstList[i][0],secondList[j][0]);
                ans.push_back({x,y});
                j++;
            }
        }
        return ans;
    }
};