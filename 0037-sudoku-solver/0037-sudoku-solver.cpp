class Solution {
public:

    bool isvalid(vector<vector<char>>&board,int row,int col,char tar){
         
          //checking row
          for(int i=0;i<9;i++){
            if(board[row][i]==tar) return false;
            if(board[i][col]==tar) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==tar) return false;
          }

          return true;

    }
 
    bool solve(vector<vector<char>>&board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        char tar=k+'0';
                        if(isvalid(board,i,j,tar)){
                            
                            board[i][j]=tar;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
     return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};