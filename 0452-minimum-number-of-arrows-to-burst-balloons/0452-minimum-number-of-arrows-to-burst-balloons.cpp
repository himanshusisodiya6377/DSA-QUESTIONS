class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        int i=0,j=1;
        int count=1;
        sort(begin(points),end(points));
        while(j<n){
            vector<int>first=points[i];
            vector<int>second=points[j];
            int cf=first[0];
            int ce=first[1];
            int bf=second[0];
            int be=second[1];
            if(ce<bf){ //no overlapping
                i=j;
                j++;
                count++;
            }
            else if(ce<=be){//overlapping
                 j++;
            }
            else if(ce>be){
                i=j;
                j++;
            }
        }
        return count;
    }
};