class Solution {
    public int maxProfit(int[] prices) {
        
       int last = prices[0], ans = 0;
        for(int i=1;i<prices.length;i++){
          if(last < prices[i]){
            ans = Math.max(ans, prices[i] - last);
          }
          last = Math.min(last, prices[i]);
        }

        return ans;
    }
}