class Solution {
   
   int help(int idx, int[] dp , int[] nums){
    if(idx == 0) return nums[0];
    if(idx < 0) return 0;

    if(dp[idx] != -1) return dp[idx];

    int pick = nums[idx] + help(idx-2,dp,nums);
    int npick = help(idx-1,dp,nums);

    return dp[idx] = Math.max(pick,npick);

   }
    
    public int rob(int[] nums) {
        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        int[] dp = new int[nums.length];
        Arrays.fill(dp,-1);
         int n = nums.length-1;
        help(n,dp,nums);
       
       // if(dp[n] == -1) return 0;
        return dp[n];
    }
}