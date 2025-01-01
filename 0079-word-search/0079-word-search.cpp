class Solution {
public:
bool search(vector<vector<char>>& board, string& word,int r,int c,int k,int idx){
      if(k == word.size()){
    return true;
   }
   if(r<0 || c<0 || r == board.size() || c == board[0].size() || board[r][c] != word[idx] ){
    return false;
   }
 
   char ch = board[r][c];
   board[r][c] = '#';
   bool a1 = search(board,word,r+1,c,k+1,idx+1);
   bool a2 = search(board,word,r-1,c,k+1,idx+1);
   bool a3 = search(board,word,r,c+1,k+1,idx+1);
   bool a4 = search(board,word,r,c-1,k+1,idx+1);
   board[r][c] = ch;

   return a1 || a2|| a3 || a4;

}
    bool exist(vector<vector<char>>& board, string word) {
       

          for(int i =0 ; i < board.size(); i++){
              for(int j =0 ; j < board[0].size(); j++){
                if(board[i][j] == word[0]) {
                    if(search(board,word,i,j,0,0)) return true;
                }
          }
          }
          return false;
       
    }
};