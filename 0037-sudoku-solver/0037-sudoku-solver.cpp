class Solution {
public:
 
    bool isvalid(int i,int j,int k,vector<unordered_set<char>>&col,vector<unordered_set<char>>&row,vector<unordered_set<char>>&grid){

        char tar=k+'0';

          if(row[i].find(tar)!=row[i].end()) return false;
          if(col[j].find(tar)!=col[j].end()) return false;
          
          if(i<=2 && j<=2 && grid[0].find(tar)!=grid[0].end()){
                    return false;
                }
                else if((i<=2) && (j>2 && j<=5) && grid[1].find(tar)!=grid[1].end()){
                    return false;
                }
                else if(i<=2 && j>5 && grid[2].find(tar)!=grid[2].end()){
                    return false;
                }
                else if((i>2 && i<=5) && j<=2 && grid[3].find(tar)!=grid[3].end()){
                    return false;
                }
                else if((i>2 && i<=5) && (j>2 && j<=5) && grid[4].find(tar)!=grid[4].end()){
                    return false;
                }
                else if((i>2 && i<=5) && j>5 && grid[5].find(tar)!=grid[5].end()){
                    return false;
                }
                else if(i>5 && j<=2 && grid[6].find(tar)!=grid[6].end()){
                    return false;
                }
                else if(i>5 && (j>2 && j<=5) && grid[7].find(tar)!=grid[7].end()){
                      return false;
                }
                else if(i>5 && (j>5) && grid[8].find(tar)!=grid[8].end()){
                     return false;
                }

        return true;
    }

   bool solve(vector<vector<char>>& board,
           vector<unordered_set<char>>& col,
           vector<unordered_set<char>>& row,
           vector<unordered_set<char>>& grid) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (int k = 1; k <= 9; k++) {
                    char tar = k + '0';
                    if (isvalid(i, j, k, col, row, grid)) {
                        board[i][j] = tar;
                        row[i].insert(tar);
                        col[j].insert(tar);

                        int g = (i / 3) * 3 + (j / 3);
                        grid[g].insert(tar);

                        if (solve(board, col, row, grid)) return true;

                        // Backtrack
                        board[i][j] = '.';
                        row[i].erase(tar);
                        col[j].erase(tar);
                        grid[g].erase(tar);
                    }
                }
                return false;  // No valid number found for this cell
            }
        }
    }

    return true;  // Solved all cells
}

    void solveSudoku(vector<vector<char>>& board) {

           
    vector<unordered_set<char>>col(9);
    vector<unordered_set<char>>row(9);
    vector<unordered_set<char>>grid(9);
        
       //inserting intial data
       for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){

            if(board[i][j]!='.'){
                col[j].insert(board[i][j]);
                row[i].insert(board[i][j]);

                //inserting in grid
                if(i<=2 && j<=2){
                    grid[0].insert(board[i][j]);
                }
                else if((i<=2) && (j>2 && j<=5)){
                    grid[1].insert(board[i][j]);
                }
                else if(i<=2 && j>5){
                    grid[2].insert(board[i][j]);
                }
                else if((i>2 && i<=5) && j<=2){
                    grid[3].insert(board[i][j]);
                }
                else if((i>2 && i<=5) && (j>2 && j<=5)){
                    grid[4].insert(board[i][j]);
                }
                else if((i>2 && i<=5) && j>5){
                    grid[5].insert(board[i][j]);
                }
                else if(i>5 && j<=2){
                    grid[6].insert(board[i][j]);
                }
                else if(i>5 && (j>2 && j<=5)){
                    grid[7].insert(board[i][j]);
                }
                else{
                    grid[8].insert(board[i][j]);
                }
            }

        }
       }

       solve(board,col,row,grid);

    }
};