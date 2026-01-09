class Solution {
    int helper(int i, int j,int[] arr,int[][]dp){
       if(i>j){
           return 0;
       }
       if(dp[i][j] != -1) return dp[i][j];
        int ans = Integer.MAX_VALUE;
       for(int idx = i ;idx<=j;idx++){
           ans = Math.min(ans,(arr[j+1] - arr[i-1] + helper(i,idx-1,arr,dp) + helper(idx+1,j,arr,dp)));
       }
       return dp[i][j] = ans;
    }
    public int minCost(int n, int[] cuts) {
        Arrays.sort(cuts);
        int[][] dp = new int[cuts.length+2][cuts.length+2];
        int[] arr = new int[cuts.length+2];

        for(int[] a : dp){
            Arrays.fill(a,-1);
        }
        arr[0] = 0;
        for(int i =0;i<cuts.length;i++){
           arr[i+1] = cuts[i];
        }
        arr[cuts.length+1] = n;

        return helper(1,cuts.length,arr,dp);
    }
}