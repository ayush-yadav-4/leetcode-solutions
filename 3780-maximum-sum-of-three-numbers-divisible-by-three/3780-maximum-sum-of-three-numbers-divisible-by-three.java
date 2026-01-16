class Solution {

    int helper(int idx, int mod, int elem , int[][][]dp,int[] nums){
      
      if(elem == 3){
          return (mod == 0) ? 0 : -10000000;
      }
      if(idx == nums.length) return -1000000;
      if(dp[idx][mod][elem] != -1) return dp[idx][mod][elem];
      int pick = nums[idx] + helper(idx+1,(mod + nums[idx])%3,elem+1,dp,nums);

      int notpick = helper(idx+1,mod,elem,dp,nums);

      return dp[idx][mod][elem] = Math.max(notpick , pick);
    }
    public int maximumSum(int[] nums) {
        // Arrays.sort(nums);
        //   int sum = 0, ans =0;
        // for(int i = 0;i<=nums.length-3;i++){
        //       sum = 0;
        //       for(int j = i;j<(i+3);j++){
        //         sum += nums[j];
                
                
        // }
        // if(sum % 3 == 0){ans = Math.max(ans,sum);}
        // }

        int[][][] dp = new int[nums.length][3][3];
         for(int[][] a: dp){
            for(int[] b : a){
                Arrays.fill(b,-1);
            }
         }


        int ans =  helper(0,0,0,dp,nums);
        if(ans < 0) return 0;
        return ans;
    }
}