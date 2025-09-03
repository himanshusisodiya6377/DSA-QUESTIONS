class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]) 
        return a[0]<b[0];
        return b[1]<a[1];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int n=points.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int min_y=INT_MIN;
            int x=points[i][0];
            int y=points[i][1];
            for(int j=i+1;j<n;j++){
                int new_x=points[j][0];
                int new_y=points[j][1];
                if(new_x>=x && new_y<=y && new_y>min_y){
                    cnt++;
                    min_y=max(min_y,new_y);
                }
            }
        }
        return cnt;
    }
};