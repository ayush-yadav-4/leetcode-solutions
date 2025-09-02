class Solution {
    public int helper(int[] prices,int idx,int buy,int cap,int[][][]dp){
    if(idx == prices.length) return 0;
    
    if(cap == 0) return 0;
    if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
    if(buy== 1){
       return dp[idx][buy][cap] = Math.max(-prices[idx] + helper(prices,idx+1,0,cap,dp),helper(prices,idx+1,1,cap,dp));
    }
    
      return dp[idx][buy][cap] = Math.max(prices[idx] + helper(prices,idx+1,1,cap-1,dp),0+helper(prices,idx+1,0,cap,dp));
    
    }
    public int maxProfit(int[] prices) {
        
        int[][][] dp = new int[prices.length+1][2][3];
        
        // return helper(prices,0,1,2,dp);
        for(int idx = prices.length-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                for(int cap = 1;cap<3;cap++){
                     if(buy == 1){
                        dp[idx][buy][cap] = Math.max(-prices[idx] + dp[idx+1][0][cap],dp[idx+1][1][cap]);
                     }
                     else{
                        dp[idx][buy][cap] = Math.max(prices[idx] + dp[idx+1][1][cap-1],dp[idx+1][0][cap]);
                     }
                }
            }
        }
         return dp[0][1][2];
       
    }
}