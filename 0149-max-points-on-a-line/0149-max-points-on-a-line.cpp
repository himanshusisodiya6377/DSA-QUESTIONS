class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi=1;
        int n=points.size();
        for(int i=0;i<n;i++){ //x1 y1

            for(int j=i+1;j<n;j++){ //x2 y2
                int cnt=0;
                for(int k=0;k<n;k++){
                    if(((points[k][1]-points[i][1])*(points[j][0]-points[i][0]))==((points[j][1]-points[i][1])*(points[k][0]-points[i][0]))) cnt++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};