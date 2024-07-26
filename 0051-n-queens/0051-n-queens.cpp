class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
          vector<vector<string>> ans;
          vector<string> board(n);

          for(int i =0; i < n;i++){
            for(int j =0; j < n;j++){
             board[i].push_back('.');
          }
          }
        vector<int>col(n,0);
        helper(ans,board,0,n,col);
        return ans;
    }

    void helper( vector<vector<string>> & ans,vector<string>&board , int row,int n,vector<int>&col){
      
      if(row == n ){
         ans.push_back(board);
         return;
      }

      for(int j =0; j <n ; j++){
         if( col[j] == 0 &&isSafe(board,row,j,n) ){
            col[j] == 1;
            board[row][j] = 'Q';
            helper(ans,board,row+1,n,col);
            col[j] =0;
            board[row][j] = '.';
         }
      }
    }

    bool isSafe(vector<string>&board , int row , int col,int n){
      
      for(int i =0 ; i < row ; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
      }

        for(int i =col ; i >= 0 ; i--){
        if(board[row][i] == 'Q'){
            return false;
        }
      }

      int i = row; int j = col;
      while(i> -1 && j > -1){
         if(board[i][j] == 'Q'){
            return false;
        }
        i--; j--;
      }

      i = row, j = col;
        while(i> -1 && j < n){
         if(board[i][j] == 'Q'){
            return false;
        }
        i--; j++;
      }

      return true;


    }
};