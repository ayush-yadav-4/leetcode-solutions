class Solution {

   
    int help(int m , int n , int[][] dp , int[][] grid){
      if(m<0 || n<0 || m >= grid.length ||n >= grid[0].length) return Integer.MAX_VALUE;
      if(m == 0) return grid[m][n];

      if(dp[m][n] != -1) return dp[m][n];

      int down = help(m-1,n,dp,grid);
      int left = help(m-1,n-1,dp,grid);
      int right = help(m-1,n+1,dp,grid);

      return dp[m][n] = grid[m][n] + Math.min(down, Math.min(left,right));
    }

    
    public int minFallingPathSum(int[][] grid) {
         int[][] dp = new int[grid.length][grid[0].length];
        int ans = Integer.MAX_VALUE;        
        int m = grid.length-1;
        // for(int i=0;i<grid[m].length;i++){
        //     for(int[] arr : dp){
        //    Arrays.fill(arr,-1);
        //  } 
        //  ans = Math.min(ans, help(m,i,dp,grid));
        //  }
       //return ans;
       int n = grid.length-1;
       for(int i=0;i<grid[n].length;i++){
         dp[n][i] = grid[n][i];
       }
       for(int i=grid.length-2;i>=0;i--){
        for(int j=0;j<grid[i].length;j++){
            int left = Integer.MAX_VALUE;
int down = dp[i+1][j];
int right = Integer.MAX_VALUE;
            if(j>0) left = dp[i+1][j-1];
            
            if(j< grid[i].length-1)right = dp[i+1][j+1];
          dp[i][j] = grid[i][j] +  Math.min(down, Math.min(left,right));
        }
       }
       
       for(int i=0;i<grid[0].length;i++){
         ans = Math.min(ans, dp[0][i]);
       }
       return ans;

    }
}