class Solution {
public:
bool isSafe(vector<vector<char>>& board,int row,int col,char elem){

for(int i =0 ; i < 9; i++){
  if(board[row][i] == elem) return false;
}
for(int i =0 ; i < 9; i++){
  if(board[i][col] == elem) return false;
}
int srow = (row/3)*3;
int scol = (col/3)*3;

for(int i = srow; i<=srow+2;i++){
    for(int j = scol; j<=scol+2;j++){
            if(board[i][j] == elem) return false;
    }
}
return true;
 

}
bool SS(vector<vector<char>>& board,int row,int col){
      if(row == 9){
       return true;
  }
  int nrow = row; int ncol = col+1;
  if(ncol == 9){
    ncol=0;
    nrow = row+1;
  }
  if(board[row][col] != '.'){
  return SS(board,nrow,ncol);
  }

  for(char i ='1' ; i <='9'; i++){
   if(isSafe(board,row,col,i)){
      board[row][col] = i;
      if(SS(board,nrow,ncol)){ return true;}
      board[row][col] = '.';  
   }
  }
  return false;
}
    void solveSudoku(vector<vector<char>>& board) {
  
    SS(board,0,0);

    }
};