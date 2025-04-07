class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
       int r=points.size();
   int sum=0;
   for(int i=0;i<r-1;i++){
      int result=0;
      int diff1=abs(points[i+1][0]-points[i][0]);
      int diff2=abs(points[i+1][1]-points[i][1]);
      if(diff1>diff2){
         sum+=diff2;
         if(points[i][0]>points[i+1][0]) points[i][0]-=diff2;
         else points[i][0]+=diff2;
         sum+=abs(points[i+1][0]-points[i][0]);
      }
      else{
         sum+=diff1;
         if(points[i][1]>points[i+1][1]) points[i][1]-=diff1;
         else points[i][1]+=diff1;
         sum+=abs(points[i+1][1]-points[i][1]);
      }
   }
    return sum;
    }
};