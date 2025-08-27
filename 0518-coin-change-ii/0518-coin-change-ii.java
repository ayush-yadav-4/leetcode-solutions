class Solution {
    public int helper(int coins[],int idx,int target,int[][]dp){
        if(idx<0) return 0;
        if(idx == 0){
            if(target%coins[idx] == 0)return 1;
            return 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target];

        int notake = helper(coins,idx-1,target,dp);
        int take = 0;
        if(coins[idx]<=target){
            take = helper(coins,idx,target-coins[idx],dp);

        }
        return dp[idx][target] = take + notake;
    }
    public int change(int amount, int[] coins) {
       
       
        int[][]dp = new int[coins.length][amount+1];
        
         for(int i=0;i<=amount;i++){
           dp[0][i] = (i%coins[0] == 0)?1:0;
        }

        for(int i=1;i<coins.length;i++){
            for(int j = 0;j<=amount;j++){
              int nopick = dp[i-1][j];
              int pick = 0;
              if(coins[i] <= j){
                pick = dp[i][j-coins[i]];
              }
              dp[i][j] = pick + nopick;
            }
        }
        return dp[coins.length-1][amount];
        // return helper(coins,coins.length-1,amount,dp);
        
    }
}