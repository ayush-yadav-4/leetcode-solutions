class Solution {

    int help(int m, int n, int[][] grid, int[][] dp){
        if(m<0 || n<0) return Integer.MAX_VALUE;
        if(m == 0 && n == 0) return grid[m][n];

        if(dp[m][n] != -1) return dp[m][n];

        int up = 0, right = 0;

        up = help(m-1,n,grid,dp) ;
         right =  help(m,n-1,grid,dp); 

        return dp[m][n] = grid[m][n] + Math.min(up,right);
    }

    public int minPathSum(int[][] grid) {
        int[][] dp = new int[grid.length+1][grid[0].length+1];

        for(int[] arr : dp){
          Arrays.fill(arr,-1);
        }

        return help(grid.length-1,grid[0].length-1,grid,dp);
    }
}