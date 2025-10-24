class Solution {
    int fibo(int n, int[]dp){
      if(n==0) return 0;
      if(n==1) return 1;
      if(n<0) return 0;
      if(dp[n] != -1) return dp[n];

      return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
    }
    public int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
       
        fibo(n,dp);
        return dp[n];
    }
}