class Solution {
   
   int help(int idx , int[] nums, int[][] dp,int previdx){
       if(idx == nums.length) return 0;

       if(dp[idx][previdx+1] != -1) return dp[idx][previdx+1];

       if(previdx == -1 || nums[previdx] < nums[idx]){
        return dp[idx][previdx+1] = Math.max(1+help(idx+1,nums,dp,idx),help(idx+1,nums,dp,previdx));
       }
       return dp[idx][previdx+1] = help(idx+1,nums,dp,previdx);
   }
    
    public int lengthOfLIS(int[] nums) {
       
         int[][] dp = new int[nums.length][nums.length+1];

         for(int[] a: dp){
          Arrays.fill(a,-1);
         }
         

          return help(0,nums,dp,-1);
        
          
    }
}