class Solution {
    boolean helper(int[] nums, int idx,boolean[][][]dp,int sum1,int sum2){
        if(idx < 0){
            if(sum1 == sum2) return true;
            return false;
        }

        if(dp[idx][sum1][sum2]) return dp[idx][sum1][sum2];

        return dp[idx][sum1][sum2] = helper(nums,idx-1,dp,sum1+nums[idx],sum2) || helper(nums,idx-1,dp,sum1,sum2+nums[idx]);
    }
    public boolean canPartition(int[] nums) {
        int sum  = 0;
        for(int i=0;i<nums.length;i++){
          sum+= nums[i];
        }
        if(sum%2 != 0 ) return false;
        sum = sum/2;
        boolean[][] dp = new boolean[nums.length+1][sum+1];

        
            for(boolean[]row1:dp){
                Arrays.fill(row1,false);
            }
        
    //   int idx = nums.length-1,sum1 = 0,sum2 = 0;
    //     return helper(nums,idx,dp,sum1,sum2);

        dp[0][0] = true;
      
        for(int idx=1;idx<=nums.length;idx++){
            for(int sum1 = 0;sum1<=sum;sum1++){
                

                    if(sum1 == 0){
                         dp[idx][sum1] = true;
                    }
                    boolean take1 = false;
                   if(sum1 >= nums[idx-1]){
                        take1 = dp[idx-1][sum1 - nums[idx-1]];
                   }
                   boolean nottake = dp[idx-1][sum1];
                   

                   dp[idx][sum1] =  take1 || nottake;
                
            }
        }

        

        return dp[nums.length][sum];



    }
}