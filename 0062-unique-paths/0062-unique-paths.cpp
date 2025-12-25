class Solution {
public:

    int helper(int n,int m,vector<vector<int>>&dp){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
          if(dp[n][m] != -1) return dp[n][m];
        return dp[n][m] = helper(n-1,m,dp) + helper(n,m-1,dp);
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return helper(n-1,m-1,dp);
    }
};