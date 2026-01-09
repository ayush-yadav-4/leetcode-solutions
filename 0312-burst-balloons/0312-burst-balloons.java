class Solution {
    int helper(int i,int j,int[] arr,int[][] dp){
        if(i>j) return 0;
         if(dp[i][j] != -1) return dp[i][j];
        
        int ans = Integer.MIN_VALUE;
        for(int idx = i;idx<=j;idx++){
           ans = Math.max(ans, (arr[i-1] * arr[idx] * arr[j+1] + helper(i,idx-1,arr,dp) + helper(idx+1,j,arr,dp)));
        }

        return dp[i][j] = ans;
    }
    public int maxCoins(int[] nums) {
        int dp[][] = new int[nums.length+1][nums.length+1];
        int arr[] = new int[nums.length+2];
        arr[0] = 1;
        for(int i =0;i<nums.length;i++){
          arr[i+1] = nums[i];
        }
        arr[nums.length+1] = 1;
        for(int[] a : dp){
         Arrays.fill(a,-1);
        }

        return helper(1,nums.length,arr,dp);
    }
}