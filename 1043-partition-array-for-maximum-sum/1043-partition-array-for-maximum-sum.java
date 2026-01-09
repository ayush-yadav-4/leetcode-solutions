class Solution {
    int helper(int idx,int[]arr,int[]dp,int k){
       
       if(idx == arr.length) return 0;

       if(dp[idx]!= -1) return dp[idx];
         int len =0,maxi =0,ans = 0;
       for(int i = idx;i<Math.min(arr.length,idx+k);i++){
           len++;
           maxi = Math.max(maxi,arr[i]);
           ans = Math.max(ans,(maxi * len) + helper(i+1,arr,dp,k));
       }

       return dp[idx] = ans;
    }
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int[] dp = new int[arr.length];
        Arrays.fill(dp,-1);
        return helper(0,arr,dp,k);
    }
} 