class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        int r=matrix.size();
        int c=matrix[0].size();

        vector<vector<int>>ans(r,vector<int>(c,0));
         
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]=matrix[i][j] ^ (i>0 ? ans[i-1][j] : 0) ^ (j>0 ? ans[i][j-1] : 0) ^ ((i>0 && j>0) ? ans[i-1][j-1] : 0); 
                // cout<<ans[i][j]<<" ";
                pq.push(ans[i][j]);
                if(pq.size()>k) pq.pop();
            }
            // cout<<endl;
        }

        return pq.top();
    }
};