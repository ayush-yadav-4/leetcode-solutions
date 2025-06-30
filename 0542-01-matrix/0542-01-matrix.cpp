class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>>visited(mat.size(),vector<int>(mat[0].size(),0));
       queue<pair<int,pair<int,int>>>q;
       for(int i =0 ;i<mat.size();i++){
          for(int j =0 ;j<mat[0].size();j++){
              if(mat[i][j] == 0){
               
                visited[i][j] =1;
                q.push({i,{j,0}});
              }
              else{
                    
              }
          }
        }
        int rows[] = {0,0,-1,+1};
        int cols[] = {-1,+1,0,0};
        while(!q.empty()){
          int r = q.front().first;
          int c = q.front().second.first;
          int wt = q.front().second.second;
           q.pop();
              mat[r][c] = wt;

          for(int i=0;i<4;i++){
             int row = r + rows[i];
              int col = c + cols[i];
             

              if(row>=0 && row < mat.size() && col>=0 && col<mat[0].size() && visited[row][col] == 0){
                visited[row][col] = 1;
                q.push({row,{col,wt+1}});

              } 
          }
        }
        return mat;
    }
};