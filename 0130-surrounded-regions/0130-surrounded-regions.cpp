class Solution {
public:

    void dfs(vector<vector<char>>&board,vector<vector<bool>>&visit,int row,int col,int i,int j){
        if(i<0 || j<0 || i>=row || j>=col || visit[i][j]==true || board[i][j]=='X') return;
        visit[i][j]=true;
       
       //right
       dfs(board,visit,row,col,i,j+1);
       //left
       dfs(board,visit,row,col,i,j-1);
       //up
       dfs(board,visit,row,col,i-1,j);
       //down
       dfs(board,visit,row,col,i+1,j);
    }

    void solve(vector<vector<char>>& board) {
       int r=board.size();
       int c=board[0].size();
       vector<vector<bool>>visit(r,vector<bool>(c,false));
    //    for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){

    //             bool flag=true;
    //         if(board[i][j]=='O' && visit[i][j]==false && (i==0 || i==r-1 || j==0 || j==c-1)){
    //             bool check=false; 
    //             dfs(board,visit,r,c,i,j,flag,check);
    //         }
    //         else if(board[i][j]=='O' && visit[i][j]==false){
    //             bool check=true;
    //             dfs(board,visit,r,c,i,j,flag,check);
    //         }
    //     }
    //    }  
       //oth row
       for(int i=0;i<c;i++){
           if(board[0][i]=='O' && visit[0][i]==false){
            dfs(board,visit,r,c,0,i);
           }
       }
       //last row
          for(int i=0;i<c;i++){
           if(board[r-1][i]=='O' && visit[r-1][i]==false){
            dfs(board,visit,r,c,r-1,i);
           }
       }
       //first column
          for(int i=0;i<r;i++){
           if(board[i][0]=='O' && visit[i][0]==false){
            dfs(board,visit,r,c,i,0);
           }
       }
       //last column
          for(int i=0;i<r;i++){
           if(board[i][c-1]=='O' && visit[i][c-1]==false){
            dfs(board,visit,r,c,i,c-1);
           }
       }

       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]=='O' && visit[i][j]==false) board[i][j]='X';
        }
       }
    }
};