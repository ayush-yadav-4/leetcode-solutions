class Solution {

    int helper(int[] nums,int idx ,int[] dp){
        if(idx >= nums.length){
           return 0;
        }

        if(dp[idx] != -1) return dp[idx];
        
          int pick = nums[idx] + helper(nums,idx+2,dp);
        
        int nopick = helper(nums,idx+1,dp);
       return dp[idx] = Math.max(pick,nopick);
    }
    public int rob(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp,-1);
     int ans = 0;
      return helper(nums,0,dp);
       
    }
}