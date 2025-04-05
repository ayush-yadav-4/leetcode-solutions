class Solution {
public:
void dfs(int r,int c,vector<vector<int>>&visited,vector<vector<char>>& board){
  visited[r][c] = 1;
 int nrow[] = {0,0,-1,+1};
 int ncol[] = {-1,+1,0,0};
  for(int i=0;i<4;i++){
    int row = r + nrow[i];
    int col = c + ncol[i];
    if(row>=0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == 'O' && visited[row][col] == 0){
       visited[row][col] = 1;
       dfs(row,col,visited,board);
    }

  }
}
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0));
        queue<pair<int,int>>q;

        int m = board.size()-1;
        for(int i=0;i<board.size();i++){
         for(int j=0;j<board[i].size();j++){
            if( i == 0 && board[i][j] == 'O' && visited[i][j] == 0){
              dfs(i,j,visited,board);
            }
            if(i == board.size()-1 && board[i][j] == 'O' && visited[i][j] == 0){
                  dfs(i,j,visited,board);
            }
             if(j == 0 && board[i][j] == 'O' && visited[i][j] == 0){
                  dfs(i,j,visited,board);
            }
            if(j == board[i].size()-1 && board[i][j] == 'O' && visited[i][j] == 0){
                  dfs(i,j,visited,board);
            }
         }
        }
       
        int row[] ={0,0,+1,-1};
     int col[] = {-1,+1,0,0}; 
       
       for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
          if(board[i][j] == 'O' && visited[i][j] == 0){
             board[i][j] = 'X';
          }
        }
       }
       
    }
};