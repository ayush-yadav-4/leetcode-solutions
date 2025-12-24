class Solution {
public:
int helper(int n,vector<int>&dp){
    if(n<0) return 0;
    if(n == 2) return 2;
    
    if(n==1) return 1;
    if(dp[n] != -1) return dp[n];


    return dp[n] = helper(n-2,dp) + helper(n-1,dp);
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);

        //return helper(n,dp);
       if(n == 0 || n ==1 || n==2) return n;
        dp[0] =0;
        dp[1] = 1;
        dp[2] = 2;
        int ans = 0;
        for(int i =3;i<=n;i++){
          dp[i]= dp[i-2] + dp[i-1];
         // dp[n] = ans;
        }
        return dp[dp.size()-1];
    }
};