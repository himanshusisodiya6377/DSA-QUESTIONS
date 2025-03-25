class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int r=rectangles.size();
        int c=4;
        int ans=0;
        //for verticle check
// 0 2 2 4 
// 1 0 3 2
// 2 2 3 4 
// 3 0 4 2
// 3 2 4 4
     sort(rectangles.begin(),rectangles.end());
        for(int i=0;i<r-1;i++){
            if(rectangles[i][2]<=rectangles[i+1][0]){
                ans++;
            }
            else if(rectangles[i][2]<rectangles[i+1][2]){
                continue;
            }
            else{
                rectangles[i+1][2]=rectangles[i][2];
            }
        }
        if(ans>=2) return true;
            //check for horizontal
            sort(rectangles.begin(), rectangles.end(), [](const vector<int>&  a, const vector<int>& b) {
              return a[1] < b[1];  
               });
            ans=0;
            for(int i=0;i<r-1;i++){
                if(rectangles[i][3]<=rectangles[i+1][1]){
                    ans++;
                }
                else if(rectangles[i][3]<rectangles[i+1][3]){
                    continue;
                }
                else{
                    rectangles[i+1][3]=rectangles[i][3];
                }
            }
        if(ans>=2) return true;
        return false;
    }
};