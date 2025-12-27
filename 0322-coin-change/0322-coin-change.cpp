class Solution {
public:
   int helper(int idx,int amount,vector<int>&coins,vector<vector<int>>&dp){
    
    if(idx>=coins.size())return 1e7;
    if(amount == 0) return 0;
    

    if(dp[idx][amount] != -1) return dp[idx][amount];

    int pick = INT_MAX;
    if(coins[idx]<=amount){
        
        pick = 1 + helper(idx,amount - coins[idx],coins,dp);
    }

    int nopick = helper(idx+1,amount,coins,dp);

    return dp[idx][amount] = min(pick,nopick);
   }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
       int cnt = 0;
       int ans = helper(0,amount,coins,dp);

       if(ans == 1e7) return -1;
       return ans;

    }
};