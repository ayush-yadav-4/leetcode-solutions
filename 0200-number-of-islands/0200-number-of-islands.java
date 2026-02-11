class Solution {

    void DFS(int i, int j, boolean[][] vis , char[][] grid){
        vis[i][j] = true;

       int[] rows ={0,0,+1,-1};
       int[] cols ={-1,+1,0,0};

       for(int idx=0;idx<=3;idx++){
          int row = i + rows[idx];
          int col = j + cols[idx];

          if(row >=0 && row < grid.length && col >=0 && col< grid[0].length && vis[row][col] == false && grid[row][col] == '1'){
            DFS(row, col, vis, grid);
          }
       }
    }
    public int numIslands(char[][] grid) {
        
        boolean[][]vis = new boolean[grid.length][grid[0].length];
        int cnt = 0;
        for(boolean[]a : vis){
          Arrays.fill(a, false);
        }
        for(int i=0;i<grid.length;i++){
         for(int j=0;j<grid[i].length;j++){
            if(vis[i][j] == false && grid[i][j] == '1'){
                cnt++;
                DFS(i, j, vis, grid);
            }
         }
        }
        return cnt;
    }
}