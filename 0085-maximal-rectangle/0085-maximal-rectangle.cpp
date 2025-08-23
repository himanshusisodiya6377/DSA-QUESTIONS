class Solution {
public:

//presmall
//nextsmall

    int solve(vector<int>&heights){
         int n=heights.size();
         vector<int>pre(n,-1);
         vector<int>next(n,n);

         stack<int>presm;
         presm.push(0);

         for(int i=1;i<n;i++){
            while(presm.size()>0 && heights[presm.top()]>=heights[i]) presm.pop();
            if(presm.size()>0) pre[i]=presm.top();
            presm.push(i);
         }

         stack<int>nextsm;
         nextsm.push(n-1);

         for(int i=n-2;i>=0;i--){
           while(nextsm.size()>0 && heights[nextsm.top()]>=heights[i]) nextsm.pop();
            if(nextsm.size()>0) next[i]=nextsm.top();
            nextsm.push(i);
            
         }

         int area=INT_MIN;

         for(int i=0;i<n;i++){
            int ar=heights[i]*((next[i]-pre[i])-1);
            area=max(ar,area);
         }
        
        return area;

    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row=matrix.size();
        int col=matrix[0].size();

        vector<int>ans(col,0);

        int maxi=INT_MIN;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1') ans[j]++;
                else ans[j]=0;
            }
            maxi=max(maxi,solve(ans));
        }

        return maxi;

    }
};