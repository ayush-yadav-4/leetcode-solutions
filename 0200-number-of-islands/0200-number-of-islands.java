class Solution {

    void DFS(char[][] grid, int i, int j, int[][] vis){
      
      vis[i][j] = 1;

      int[] row = {-1,+1,0,0};
      int[] col = {0,0,-1,+1};

      for(int idx=0;idx<4;idx++){
        int r = i + row[idx];
        int c = j + col[idx];

        if( r >=0 && r < grid.length && c>=0 && c < grid[0].length && grid[r][c] == '1' && vis[r][c] == 0){
          DFS(grid,r,c,vis);
        }
      }
    }
    public int numIslands(char[][] grid) {
        
       int[][] vis = new int[grid.length][grid[0].length];
       int ans = 0;
       for(int i=0;i<grid.length;i++){
        for(int j=0;j<grid[0].length;j++){
           
           if(grid[i][j] == '1' && vis[i][j] == 0){
            DFS(grid,i,j,vis);
            ans++;
           }
        }
       }

       return ans;
    }
}