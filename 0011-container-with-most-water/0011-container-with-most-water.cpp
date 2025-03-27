class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int maxi=INT_MIN;
        while(i<j){
          int width=j-i;
          int h=min(height[i],height[j]);
          int area=width*h;
          if(area>maxi) maxi=area;
          if(height[i]<height[j]) i++;
          else if(height[i]>height[j]) j--;
          else {
            i++;
            j--;
          }
        }
        return maxi;
    }
};