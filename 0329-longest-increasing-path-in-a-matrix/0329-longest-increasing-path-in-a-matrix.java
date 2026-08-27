class Solution {
   
    int DFS(int[][] grid, int i, int j, int[][] dp, int time){
      
     if(dp[i][j] != -1) return dp[i][j];

      int[] row = {-1,+1,0,0};
      int[] col = {0,0,-1,+1};
      int ans = 1;
     
      for(int idx=0;idx<4;idx++){
        int r = i + row[idx];
        int c = j + col[idx];

        if( r >=0 && r < grid.length && c>=0 && c < grid[0].length && grid[r][c] > grid[i][j]){
            
          ans = Math.max(ans, 1+ DFS(grid,r,c,dp,time+1));
        }
      }
      dp[i][j] = ans;
      return ans;
    }
    public int longestIncreasingPath(int[][] mat) {
        int[][] dp = new int[mat.length][mat[0].length];

        for(int[]a : dp){
            Arrays.fill(a,-1);
          } 

      int ans = 0;
      for(int i=0;i<mat.length;i++){
        for(int j=0;j<mat[0].length;j++){
           
          ans = Math.max(ans,DFS(mat,i,j,dp,1));
        }
      }
         return ans;
    }
}