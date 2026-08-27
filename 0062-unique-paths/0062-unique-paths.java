class Solution {

    int help(int m, int n , int[][] dp){
      if(m<0 || n < 0) return 0;
      if(m == 0 && n == 0) return 1;

      if(dp[m][n] != -1) return dp[m][n];

      return dp[m][n] = help(m-1,n,dp) + help(m,n-1,dp);
    }
    public int uniquePaths(int m, int n) {
        if(m==1 && n == 1) return 1;
        int[][] dp = new int[m][n];
        for(int[]a : dp){
         Arrays.fill(a,-1);
        }
         return help(m-1,n-1,dp);
        // return dp[m-1][n-1];

        // dp[0][0] = 1;
        
       
        // for(int i = 0;i<m;i++){
        //     for(int j = 0;j<n;j++){
        //       if(i == 0 && j ==0) continue;
        //        int up = 0, right=0;
        //       if(i>0) up = dp[i-1][j];
        //       if(j>0) right = dp[i][j-1];
        //       dp[i][j] = up + right;
        //     }
        // }
        // return dp[m-1][n-1];
    }
}