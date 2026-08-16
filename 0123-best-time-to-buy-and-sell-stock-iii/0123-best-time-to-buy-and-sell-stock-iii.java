class Solution {

    int help(int idx, int[] prices , int[][][]dp, int buy, int cnt){
      if(idx == prices.length || cnt == 2) return 0;
    

      if(dp[idx][buy][cnt] != -1) return dp[idx][buy][cnt];

      if(buy == 1){
        return dp[idx][buy][cnt] = Math.max(-prices[idx] + help(idx+1,prices,dp,0,cnt), help(idx+1,prices,dp,1,cnt));

      }
     

      return dp[idx][buy][cnt] = Math.max(prices[idx] + help(idx+1,prices,dp,1,cnt+1), help(idx+1,prices,dp,0,cnt));
    }
    public int maxProfit(int[] prices) {
        int[][][]dp = new int[prices.length][2][2];
        
        for(int[][] a: dp){
          for(int[] b: a){
           Arrays.fill(b,-1);
        }
        }

        return help(0,prices,dp,1,0);
    }
}