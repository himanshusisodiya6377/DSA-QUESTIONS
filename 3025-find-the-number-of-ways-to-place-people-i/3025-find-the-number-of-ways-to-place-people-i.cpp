class Solution {
public:

    bool check(int i,int j,vector<vector<int>>&points){
                int old_x = points[i][0];
                int old_y = points[i][1];
                int new_x = points[j][0];
                int new_y = points[j][1];
                for(int k=0;k<points.size();k++){
                    if(k!=i && k!=j){
                    int x=points[k][0];
                    int y=points[k][1];
                    if((x>=old_x && x<=new_x) && (y<=old_y && y>=new_y)) return false;
                    }
                }
                return true;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = i + 1; j < n; j++) {

                int old_x = points[i][0];
                int old_y = points[i][1];
                int new_x = points[j][0];
                int new_y = points[j][1];
                if (flag == false && (new_x >= old_x && new_y <= old_y ||
                                      new_x <= old_x && new_y >= old_y) && check(i,j,points)){
                    cnt++;
                flag = true;
                                      }
                else {
                    if (new_x >= old_x && new_y == old_y)
                        cnt++;
                }
            }
        }
    return cnt;
    }
};