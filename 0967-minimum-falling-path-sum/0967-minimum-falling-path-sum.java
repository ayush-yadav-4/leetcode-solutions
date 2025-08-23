import java.util.*;

class Solution {
    
   



    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int[][] dp = new int[n][m];
       
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

           for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                 int up = dp[i-1][j];
                int leftdg = (j > 0) ? dp[i-1][j-1] : (int)1e9;
                int rightdg = (j < m-1) ? dp[i-1][j+1] : (int)1e9;
                dp[i][j] = matrix[i][j] + Math.min(up, Math.min(leftdg, rightdg));

            }
        }
        int ans = Integer.MAX_VALUE;
        for (int j = 0; j < m; j++) {
            ans = Math.min(ans,dp[matrix.length-1][j]);
        }
        return ans;
    }
}
