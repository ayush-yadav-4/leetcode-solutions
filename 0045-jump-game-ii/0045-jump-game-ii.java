class Solution {

    int help(int[] nums , int idx, int jump, int[] dp){
       if(idx >= nums.length) return Integer.MAX_VALUE-10;
       if(idx == nums.length-1) return 0;

       if(dp[idx] != -1) return dp[idx];

       int mini = Integer.MAX_VALUE-10;
     
       for(int i=1;i<=nums[idx];i++){
         mini = Math.min(mini,1 + help(nums,idx+i, jump+1, dp));
       }
      return dp[idx] =  mini;
    }
    public int jump(int[] nums) {
        int[] dp = new int[nums.length];
       
            Arrays.fill(dp, -1);
        
       return help(nums, 0, 0, dp);

    }
}