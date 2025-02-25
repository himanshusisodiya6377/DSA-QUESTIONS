class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>v;
        for(int i=0;i<points.size();i++){
            v.push_back(points[i][0]);
        }
        sort(v.begin(),v.end());
        int maxi=INT_MIN;
        for(int i=1;i<points.size();i++){
            int x=v[i]-v[i-1];
            if(x>maxi) maxi=x;
        }
        return maxi;
    }
};