class Solution {
    public int findNumberOfLIS(int[] nums) {
        
        int[] dp = new int[nums.length];
        int[] cnt = new int[nums.length];
        Arrays.fill(cnt,1);
        Arrays.fill(dp,1);
        int maxi = 0,ans=0;
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<i;j++){
              if(nums[i] > nums[j] && dp[i] < (dp[j] + 1)){
               dp[i] = dp[j] + 1;
               cnt[i] = cnt[j];
               
              }
              else if(nums[i] > nums[j] && (dp[j] +1) == dp[i]){
               cnt[i]+= cnt[j];
              }
              
            }
            maxi = Math.max(maxi,dp[i]);
          
        }

        for(int i=0;i<nums.length;i++){
          if(maxi == dp[i]){
            ans += cnt[i];
          }
        }

        
        return ans;
    }
}