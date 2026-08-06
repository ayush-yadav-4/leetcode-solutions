class Solution {
    int help(int m , int n , int[][] dp){
       if(m< 0 || n < 0 || dp[m][n] == 0) return 0;
       if(m == 0 && n == 0) return 1;

       if(dp[m][n] != -1) return dp[m][n];

       return dp[m][n] = help(m-1,n,dp) + help(m,n-1,dp);
    }
    public int uniquePathsWithObstacles(int[][] gird) {
        int m =gird.length;
        int n = gird[0].length;
        int[][] dp = new int[m][n];

        for(int[] a : dp){
          Arrays.fill(a,-1);
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
              if(gird[i][j] == 1){
                dp[i][j] = 0;
              }
            }
        }
        return help(m-1,n-1,dp);

        
    }
}