class Solution {

    int help(int r , int c , int[][] dp){
       if(r== 0 && c< 0 || r< 0 && c== 0) return 0;
       if(r<0 || c < 0) return 0;
      if(r == 0 && c == 0){
        return 1;
      }
      if(r== 0 && c< 0 || r< 0 && c== 0) return 0;

      if(dp[r][c] != -1) return dp[r][c];

      return dp[r][c] = help(r-1,c,dp) + help(r,c-1,dp);
    } 
    public int uniquePaths(int m, int n) {
        if(m==1 && n == 1) return 1;
        int[][] dp = new int[m][n];
        for(int[]a : dp){
         Arrays.fill(a,-1);
        }
        // help(m-1,n-1,dp);
        // return dp[m-1][n-1];
        dp[0][0] = 1;
        
       
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
              if(i == 0 && j ==0) continue;
               int up = 0, right=0;
              if(i>0) up = dp[i-1][j];
              if(j>0) right = dp[i][j-1];
              dp[i][j] = up + right;
            }
        }
        return dp[m-1][n-1];
    }
}