class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(begin(points),end(points));
        int maxi=INT_MIN;
        for(int i=1;i<points.size();i++){
            int x=points[i][0]-points[i-1][0];
            if(x>maxi) maxi=x;
        }
        return maxi;
    }
};