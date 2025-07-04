class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
     int min_row = m;
        int min_col = n;
        for (int i=0; i<ops.size(); i++){
            if (ops[i][0]<min_row) min_row=ops[i][0];
            if (ops[i][1]<min_col) min_col=ops[i][1];
        }        
        return min_row*min_col;
   
   
   
   
    //  int k=ops.size();
    //  if(k==0) return m*n;
    //  int mini=INT_MAX;
    // //  vector<vector<int>>v(m,vector<int>(n,0));
    //  for(int i=0;i<k;i++){
    //     int prod=(ops[i][0])*(ops[i][1]);
    //     mini=min(mini,prod);
    //  }      

    //  for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         if(v[i][j]<0){
    //             int prod=(i+1)*(j+1);
    //             mini=min(mini,prod);
    //         }
    //     }
    //  }
      //return mini;
    }
};