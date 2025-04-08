class Solution {
public:
void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&visited){

    visited[row][col] = 1;
    int nrow[] = {0,0,-1,+1};
    int ncol[] = {-1,+1,0,0};
    for(int i=0;i<4;i++){
      int r = row + nrow[i];
       int c = col + ncol[i];

       if(r<grid.size() && r>=0&&c<grid[0].size() && c>=0 && grid[r][c] == '1' && visited[r][c] == 0){
         visited[r][c] = 1;
         dfs(r,c,grid,visited);
       }
    }

}
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                  if(grid[i][j] == '0'){
                    visited[i][j] = 1;
                  }
            } 
        }
      int ans=0;
       for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                  if(grid[i][j] == '1' && visited[i][j] == 0){
                    ans++;
                  dfs(i,j,grid,visited);
                  }
            } 
        }
        return ans;
    }
};