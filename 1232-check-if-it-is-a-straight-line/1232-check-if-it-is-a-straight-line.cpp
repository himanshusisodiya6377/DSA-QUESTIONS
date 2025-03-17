class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int r=coordinates.size();
        int c=2;
         int num=coordinates[1][1]-coordinates[0][1];
         int deno=coordinates[1][0]-coordinates[0][0];
        for(int i=1;i<r-1;i++){
                 int num1=coordinates[i+1][1]-coordinates[i][1];
                int deno1=coordinates[i+1][0]-coordinates[i][0];
            if(num*deno1!=deno*num1) return false;
        }
        return true;
    }
};