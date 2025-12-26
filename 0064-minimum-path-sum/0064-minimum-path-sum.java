class Solution {

    int helper(int i,int j,int[][] dp,int[][] grid){
        if(i == 0 && j ==0) return grid[i][j];

        if(i<0 || j<0) return Integer.MAX_VALUE;

         if(dp[i][j] != -1) return dp[i][j];
         
        int up =  helper(i-1,j,dp,grid);
        int left =  helper(i,j-1,dp,grid);

        return dp[i][j] = grid[i][j] + Math.min(up,left);
    }

    public int minPathSum(int[][] grid) {
        int[][] dp = new int[grid.length+1][grid[0].length+1];

        for(int[] arr : dp){
          Arrays.fill(arr,-1);
        }

        return helper(grid.length-1,grid[0].length-1,dp,grid);
    }
}