class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        //for rows
        vector<unordered_set<int>>row(n);
        //for coloumn
        vector<unordered_set<int>>col(n);
        // return false;
        //for sqaure
        vector<unordered_set<int>>sq(n);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                //checking row
                if(row[i].find(board[i][j])!=row[i].end()) return false;
                else if(col[j].find(board[i][j])!=col[j].end()) return false;
                else if(sq[((i/3)*3+(j/3))].find(board[i][j])!=sq[((i/3)*3+(j/3))].end()) return false;
                else{
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    sq[((i/3)*3+(j/3))].insert(board[i][j]);
                }
                }
            }
        }
      return true;
    }
};