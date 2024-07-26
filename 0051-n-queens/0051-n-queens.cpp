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
        
        helper(ans,board,0,n);
        return ans;
    }

    void helper( vector<vector<string>> & ans,vector<string>&board , int row,int n){
      
      if(row == n ){
         ans.push_back(board);
         return;
      }

      for(int j =0; j <n ; j++){
         if(isSafe(board,row,j,n) ){
           
            board[row][j] = 'Q';
            helper(ans,board,row+1,n);
           
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