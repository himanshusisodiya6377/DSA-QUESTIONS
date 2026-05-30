class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        vector<vector<char>>ans(c,vector<char>(r,'.'));
        
        int x=0,y=c-1; //intial free;
        for(int i=0;i<r;i++){
            for(int j=c-1;j>=0;j--){
                if(j==c-1){
                    x=i;
                    y=j;
                }

                //we are at obstacle
                if(grid[i][j]=='*'){
                    x=i;
                    y=j-1;
                }
                //move till get free
                while(x>=0 && y>=0 && grid[x][y]!='.'){
                    y--;
                }
                
                if(grid[i][j]=='#' && x==i && y>j){
                    grid[i][j]='.';
                    grid[x][y]='#';
                }
            }
        }

        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         // ans[j][i]=grid[i][j];
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[j][r-i-1]=grid[i][j];
            }
        }

        return ans;
    }
};