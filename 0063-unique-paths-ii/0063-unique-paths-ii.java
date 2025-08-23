class Solution {
    public static int helper(int[][] grid,int i , int j , int[][]dp){
       if (i < 0 || j < 0) return 0; 
        if (grid[i][j] == 1) return 0;
       if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
       int left = helper(grid,i,j-1,dp);
        int up = helper(grid,i-1,j,dp);

        return dp[i][j] = left + up;
    }
    public int uniquePathsWithObstacles(int[][] grid) {
        if(grid[0][0] == 1) return 0;
         if(grid.length == 1 && grid[0].length == 1 && grid[0][0] == 0) return 1;
        int[][] dp = new int[grid.length][grid[0].length];
        for(int[] row : dp){
            Arrays.fill(row,-1);
        }
        
        helper(grid,grid.length-1,grid[0].length-1,dp);
       if(dp[grid.length - 1][grid[0].length - 1] == -1) return 0;
       return dp[grid.length - 1][grid[0].length - 1];

    }
}