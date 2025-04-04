class Solution {

    //with matrix - 
    //  int rows = mat.size();
    //     int cols = mat[0].size();
    //     vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX - 1)); // Avoid overflow

    //     // First Pass: Top-Left to Bottom-Right
    //     for (int i = 0; i < rows; ++i) {
    //         for (int j = 0; j < cols; ++j) {
    //             if (mat[i][j] == 0) {
    //                 dist[i][j] = 0;
    //             } else {
    //                 if (i > 0) {
    //                     dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
    //                 }
    //                 if (j > 0) {
    //                     dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
    //                 }
    //             }
    //         }
    //     }

    //     // Second Pass: Bottom-Right to Top-Left
    //     for (int i = rows - 1; i >= 0; --i) {
    //         for (int j = cols - 1; j >= 0; --j) {
    //             if (mat[i][j] == 1) {
    //                 if (i < rows - 1) {
    //                     dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
    //                 }
    //                 if (j < cols - 1) {
    //                     dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
    //                 }
    //             }
    //         }
    //     }

    //     return dist;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       
       queue<pair<int,pair<int,int>>>q;
       vector<vector<int>>visited(mat.size(),vector<int>(mat[0].size(),0));
       vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),0));

       for(int i=0;i<mat.size();i++){
         for(int j=0;j<mat[i].size();j++){
           if(mat[i][j] == 0){
            q.push({0,{i,j}});
            visited[i][j] = 1;
           }else{
            visited[i][j] = 0;
           }
         }
       }
     int row[] ={0,0,+1,-1};
     int col[] = {-1,+1,0,0}; 
      while(!q.empty()){
         int r = q.front().second.first;
         int c = q.front().second.second;
         int occr = q.front().first;
         ans[r][c] = occr;
         q.pop();

         for(int i=0;i<4;i++){
          int nrow = r + row[i];
          int ncol = c+ col[i];

          if(nrow >=0 && nrow < mat.size() && ncol >=0 && ncol < mat[0].size() && visited[nrow][ncol]== 0 ){
              visited[nrow][ncol] = 1;
              q.push({occr+1,{nrow,ncol}});
          } 
         }
       
      }
        return ans;
    }
};