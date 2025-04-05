class Solution {
public:
void dfs(int r,int c,vector<vector<int>>&visited,vector<vector<int>>&grid){
  visited[r][c] = 1;
  int nrow[] = {0,0,-1,+1};
  int ncol[] = {-1,+1,0,0};
  for(int i=0;i< 4 ;i++){
    int row = r+ nrow[i];
    int col = c+ ncol[i];
    if(row>=0 && row<grid.size() && col >=0 && col < grid[0].size() && grid[row][col] == 1 && visited[row][col] == 0){
       visited[row][col] = 1;
       dfs(row,col,visited,grid);
    }
  }
}
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));

        for(int j = 0 ;j< grid[0].size();j++){
           if(grid[0][j] == 1 && visited[0][j] == 0){
            dfs(0,j,visited,grid);
           }
           if(grid[grid.size()-1][j] == 1 && visited[grid.size()-1][j] == 0){
            dfs(grid.size()-1,j,visited,grid);
           }
        }

           for(int i = 0 ;i< grid.size();i++){
           if(grid[i][0] == 1 && visited[i][0] == 0){
            dfs(i,0,visited,grid);
           }
           if(grid[i][grid[0].size()-1] == 1 && visited[i][grid[0].size()-1] == 0){
            dfs(i,grid[0].size()-1,visited,grid);
           }
        }
         int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
              if(grid[i][j] == 1 && visited[i][j] == 0){
                ans++;
              }
            }
        }
        return ans;
    }
};