class Solution {

    int help(int idx , int amount, int[] coins, int[][]dp){
    if(amount == 0) return 1;
       if(idx == coins.length){
        if(amount == 0) return 1;
        return 0;
       }

       if(dp[idx][amount] != -1) return dp[idx][amount];

       int pick=0 , npick = 0;

       if(coins[idx] <= amount) pick = help(idx,amount-coins[idx],coins,dp);
       npick = help(idx+1,amount,coins,dp);

       return dp[idx][amount] = pick + npick;
    }
    public int change(int amount, int[] coins) {
        //if(amount == 0) return 0;
         int[][] dp = new int[coins.length][amount+1];
        for(int[] a: dp){
            Arrays.fill(a,-1);
        }

        return help(0,amount,coins,dp);
    }
}