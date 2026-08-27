class Solution {

   int help(int[][]grid, int[][] dp, int i , int j ){
     
      if(i >= grid.length || j >= grid[0].length) return Integer.MAX_VALUE-100;
       if(i == grid.length-1 && j == grid[0].length-1) return grid[i][j];

      if(dp[i][j] != -1) return dp[i][j];

      return dp[i][j] = grid[i][j] + Math.min(help(grid, dp , i+1, j), help(grid, dp , i, j+1));
   }
    public int minPathSum(int[][] grid) {
        int[][] dp = new int[grid.length+1][grid[0].length+1];

        for(int[] arr : dp){
          Arrays.fill(arr,-1);
        }

        return help(grid, dp, 0, 0);
    }
}