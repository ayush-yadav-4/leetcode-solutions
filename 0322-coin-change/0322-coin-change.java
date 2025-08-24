class Solution {

    public static int helper(int[] coins,int idx, int sum,int[][]dp){
     
      if(idx == 0){
        if(sum % coins[idx] == 0) return sum/coins[idx];
        return (int)1e9;
      }
      if(dp[idx][sum] != -1) return dp[idx][sum];
      int nopick =0+ helper(coins,idx-1,sum,dp);
      int pick = (sum >= coins[idx])? 1+ helper(coins,idx,sum-coins[idx],dp):(int)1e9;
     

      return dp[idx][sum] = Math.min(nopick,pick);
    }
    public int coinChange(int[] coins, int amount) {
        if(amount == 0) return 0;
        int[][]dp = new int[coins.length][amount+1];

        for(int[] row : dp){
           Arrays.fill(row,-1);
        }
     int ans = helper(coins, coins.length - 1, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
}