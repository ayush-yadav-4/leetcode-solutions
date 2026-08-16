class Solution {

    int help(int idx , int[] prices , int buy, int[][]dp){
      if(idx == prices.length) return 0;
      if(dp[idx][buy] != -1) return dp[idx][buy];
      if(buy == 1){
          return dp[idx][buy] = Math.max(-prices[idx] + help(idx+1, prices, 0,dp), help(idx+1,prices,1,dp));
      }

      return dp[idx][buy] = Math.max(prices[idx] + help(idx+1, prices, 1,dp), help(idx+1,prices,0,dp));

    }
    public int maxProfit(int[] prices) {
        
        int[][] dp = new int[prices.length][2];

        for(int[] a: dp){
           Arrays.fill(a,-1);
        }

        return help(0,prices,1,dp);
    }
}