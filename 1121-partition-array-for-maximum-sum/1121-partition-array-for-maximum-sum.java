class Solution {
    public int helper(int[] arr,int idx,int[]dp,int k){
     if(idx == arr.length) return 0;
     if(dp[idx] != -1) return dp[idx];
     int maxi = Integer.MIN_VALUE,len=0,ans = Integer.MIN_VALUE;
     for(int i=idx;i<Math.min(arr.length,idx+k);i++){
         
         len++;
         maxi = Math.max(maxi,arr[i]);
        int sum = (maxi*len) + helper(arr,i+1,dp,k) ;
         ans = Math.max(ans,sum);

     }
     return dp[idx] = ans;
    }
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int[]dp = new int[arr.length];
        Arrays.fill(dp,-1);
        return helper(arr,0,dp,k);
    }
}