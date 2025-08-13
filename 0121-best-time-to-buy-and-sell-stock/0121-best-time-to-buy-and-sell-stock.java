class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0,mini  = prices[0],diff = 0;
        for(int i=1;i<prices.length;i++){
             mini = Math.min(mini,prices[i]);
            diff =  prices[i] - mini;
           
            ans = Math.max(ans,diff); 
        }

       
        return ans;
    }
}