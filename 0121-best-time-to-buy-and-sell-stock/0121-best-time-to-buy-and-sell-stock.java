class Solution {
    public int maxProfit(int[] prices) {
        int buy = Integer.MAX_VALUE, sell =0 ,diff = 0;
        for(int i = 0;i<prices.length;i++){
             sell = prices[i];
             diff = Math.max((sell - buy),diff);
             buy = Math.min(buy,prices[i]);
        }

        return diff;
    }
}