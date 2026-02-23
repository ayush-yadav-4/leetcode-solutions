class Solution {
public:
bool isSafe(int row , int col, vector<string>& board, int n){
 int r = row; int c = col;

 while(c>=0){
    if(board[r][c] == 'Q'){
       return false;
    }
    c--;
 }
 r = row; c = col;
 while(r>=0){
    if(board[r][c] == 'Q'){
     return false;
 }
 r--;
}

r = row; c = col;

while(r >=0 && c >=0){
    if(board[r][c] == 'Q'){
     return false;
 }
 r--; c--;
}
r = row; c = col;
while(r >=0 && c < n){
    if(board[r][c] == 'Q'){
     return false;
 }
 r--; c++;
}

return true;
}
void helper(int row, int col , vector<string>& board, vector<vector<string>>&ans, int n, int cnt){
    if(row == n){
        ans.push_back(board);
        return;
    }

    for(int i=0;i<n;i++){
        if(isSafe(row,i,board, n)){
           board[row][i] = 'Q';
           cnt = cnt+1;
            helper(row+1,i,board,ans,n, cnt);
            cnt = cnt-1;
            board[row][i] = '.';

        }
    }


}
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans;
         vector<string> board(n,string(n,'.'));
         helper(0,0,board,ans,n,0);
         return ans;
    }
};