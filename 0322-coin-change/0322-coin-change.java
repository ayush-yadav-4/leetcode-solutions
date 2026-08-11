class Solution {
     int help(int idx , int coins[], int amount, int[][] dp){
         if(amount ==0){
            return 0;
        }
         if(idx == coins.length && amount != 0){
           
            return Integer.MAX_VALUE-1;
        }
        
       
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int pick = Integer.MAX_VALUE, npick = Integer.MAX_VALUE;
        
        if(coins[idx] <= amount){
            pick = 1 + help(idx,coins,amount-coins[idx],dp);
        }
        npick = help(idx+1,coins,amount,dp);
        
        return dp[idx][amount] = Math.min(pick,npick);
    }
    public int coinChange(int[] coins, int amount) {
         int[][] dp = new int[coins.length][amount+1];
        for(int[] a: dp){
            Arrays.fill(a,-1);
        }
        int ans = help(0,coins, amount,dp);
        if(ans == Integer.MAX_VALUE-1) return -1;
        return ans;
    }
}