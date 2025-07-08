class Solution {
public:


  int helper(int n,vector<int>&dp){
    if(n==1) return 1;
     if(n==0) return 0;
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = helper(n-2,dp) + helper(n-1,dp);
  }
    int fib(int n) {
        if(n<=1) return n;
         vector<int>dp(n+1,-1);
         dp[0]= 0;dp[1] = 1;
        //int ans =  helper(n,dp);

        for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};