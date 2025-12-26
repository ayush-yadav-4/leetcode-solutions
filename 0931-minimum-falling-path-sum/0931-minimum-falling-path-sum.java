class Solution {

    int helper(int i,int j,int[][]dp,int[][]grid){
         if(i >= grid.length || j >= grid[0].length || j<0) return 1_000_000_000;
        if(i == grid.length-1){
            return grid[grid.length-1][j];
        }
       
         if(dp[i][j]!= -1) return dp[i][j];
        int down = helper(i+1,j,dp,grid);
        int diag_l = helper(i+1,j+1,dp,grid);
        int diag_r = helper(i+1,j-1,dp,grid);


        return dp[i][j] = grid[i][j] + Math.min(down,Math.min(diag_l,diag_r));
    }
    public int minFallingPathSum(int[][] grid) {
        
        int[][] dp = new int[grid.length+1][grid[0].length+1];

        for(int[] arr : dp){
          Arrays.fill(arr,-1);
        }
        // int ans = Integer.MAX_VALUE;
        // for(int i =0;i<grid[0].length;i++){
        //    ans = Math.min(ans, helper(0,i,dp,grid));
        // }
        // return ans;


        for(int i =0;i<grid[0].length;i++){
           dp[0][i] =grid[0][i];
       }
        for(int i = 1;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
               int down = dp[i-1][j];
              int diag_l = (j>0)?dp[i-1][j-1]:1_000_000_000;
                   int diag_r = (j<grid[0].length-1)?dp[i-1][j+1]:1_000_000_000;

               dp[i][j] = grid[i][j] + Math.min(down,Math.min(diag_l,diag_r));
            }
        }
      int ans = Integer.MAX_VALUE;
        for(int i =0;i<grid[0].length;i++){
           ans = Math.min(ans, dp[grid.length-1][i]);
        }
        return ans;
       
    }
}