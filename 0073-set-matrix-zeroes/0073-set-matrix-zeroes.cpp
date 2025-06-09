class Solution {
public:
 void setzero(vector<vector<int>>& matrix,int row,int col){
      int r =0,c=0;
      r = row,c = col;
      while(r<matrix.size()){
        matrix[r][c] = 0;
        r++;
      }
        r = row,c = col;
       while(r>=0){
        matrix[r][c] = 0;
        r--;
      }
        r = row,c = col;
       while(c<matrix[0].size()){
        matrix[r][c] = 0;
        c++;
      }
        r = row,c = col;
       while(c>=0){
        matrix[r][c] = 0;
        c--;
      }
   }
    void setZeroes(vector<vector<int>>& matrix) {
        // vector<int>row(matrix.size(),0);
        //  vector<int>col(matrix[0].size(),0);
        // if(matrix[0].size() == 1 && matrix.size()==1){
        //    return;
        // }
        
        // for(int i =0 ;i < matrix.size(); i++){
        //      for(int j =0 ; j< matrix[i].size(); j++){
        //      if(matrix[i][j] == 0){
        //         col[j] = 1;  row[i] = 1;
        //      }
        // }
        // }
        //      for(int i =0 ;i < matrix.size(); i++){
        //      for(int j =0 ; j< matrix[i].size(); j++){
        //      if(row[i] == 1 || col[j] == 1){
        //        matrix[i][j] = 0;
        //      }
        // }
        // }

        
          vector<pair<int,int>>ans;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
               if(matrix[i][j] == 0){
                ans.push_back({i,j});
               }
            }
        }

        for(auto it : ans){
           setzero(matrix,it.first,it.second);
        }
        return;
     
    }
};