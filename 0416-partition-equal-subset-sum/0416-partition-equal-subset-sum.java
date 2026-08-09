class Solution {
    boolean help(int idx, int[] nums, int target, int[][] dp){

        if(target == 0){
        return true;
    }
    if(target != 0 && idx == nums.length) return false;    
    if(idx == nums.length || target <0) return false;
    
    if(dp[idx][target] != -1) return dp[idx][target] == 1;

  boolean take =  help(idx+1,nums,target-nums[idx],dp);
  boolean ntake =  help(idx+1,nums,target,dp);

  dp[idx][target] = (take || ntake) ? 1: 0;

  return take || ntake;
    }

    public boolean canPartition(int[] nums) {
       int sum = 0;
       for(int i =0;i<nums.length;i++){
        sum += nums[i];
       }
       if(sum%2 != 0) return false;
       int target = sum/2;
       int[][] dp = new int[nums.length][target+1];
       for(int[] a: dp){
         Arrays.fill(a,-1);
       }
       return help(0,nums,target,dp);



    }
}