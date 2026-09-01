class Solution {


 
    int help(int n , int[] dp){
       if(n== 0) return 1;
       if(n < 0) return 0;
       if(dp[n]!= -1) return dp[n];
       return dp[n] = help(n-1,dp) + help(n-2,dp);
    }
    int climbStairs(int n) {
       if(n==0) return 1;
       if(n==1) return 1;
       int[] dp = new int[n+1];
       //Arrays.fill(dp,-1);
      // help(n,dp);
       dp[0] = 1;
       dp[1] = 1;
       for(int i=2;i<=n;i++){
         dp[i] = dp[i-1] + dp[i-2];
       }
       return dp[n];
    }
};