class Solution {

    // int helper(int[] coins, int amt,int idx, int[][] dp){

    //     if(amt<=0){
    //         if(amt == 0) return 0;
    //         return Interger.MIN_VALUE;
    //     }
    //     if(idx >= coins.size()){
    //           if(amt == 0) return 0;
    //         return Interger.MIN_VALUE;
    //     }

    //    int pick = 0;
    //    if(coins[idx]<=amt){
    //     pick = coins[idx] + helper(coins,amt-coins[idx],idx+1,dp);
    //    }
    //    int notpick = helper(coins,amt,idx+1,dp);

    //    return dp[idx][amt] = return Math.max(pick, notpick);
    // }
    public int coinChange(int[] coins, int amount) {
        int[][] dp = new int[coins.length + 1][amount + 1];
       
        int INF = (int)1e6;
        for(int i=0;i<=amount;i++){
             dp[0][i] = INF;
        }
        for(int i=0;i<=coins.length;i++){
             dp[i][0] = 0;
        }
        dp[0][0] = 0;

        for(int i = 1;i<=coins.length;i++){
            for(int j = 0;j<=amount;j++){
               int pick = INF;
                if (coins[i - 1] <= j && dp[i][j - coins[i - 1]] != INF) {
                    pick = dp[i][j - coins[i - 1]] + 1;
                }
                int notpick = dp[i - 1][j];

               dp[i][j] = Math.min(pick,notpick);
            }
        }

       int ans = dp[coins.length][amount];
        return ans >= INF ? -1 : ans;
    }
}