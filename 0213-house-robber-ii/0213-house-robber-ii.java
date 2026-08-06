class Solution {

    int help(int idx , int[] dp, int[] nums, int st){
      if(idx<st) return 0;
      if(idx == st){
        return nums[idx];
      }

      if(dp[idx] != -1){
        return dp[idx];
      }

      int take = 0, ntake = 0;
      
     take = nums[idx] + help(idx-2,dp,nums,st);
      ntake = help(idx-1,dp,nums,st);

      return dp[idx] = Math.max(take,ntake);
    }
    public int rob(int[] nums) {
        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        int[] dp = new int[nums.length];
        Arrays.fill(dp,-1);
         int n = nums.length-1;
        int a = help(n,dp,nums,1);

         Arrays.fill(dp,-1);
        
        int b = help(n-1,dp,nums,0);
        return Math.max(a,b);
       
       
    }
}