class Solution {
public:
    int maxArea(vector<int>& height) {
        long long n=height.size();
        long long i=0,j=n-1;
        long long maxi=INT_MIN;
        while(i<=j){
        long long mini=min(height[i],height[j]);
         long long area=mini*(j-i);
         maxi=max(maxi,area);
         if(height[i]<height[j]) i++;
         else if(height[i]>height[j]) j--;
        //  else break;
         else{
            i++;
            j--;
         }
        }
        return maxi;
    }
};