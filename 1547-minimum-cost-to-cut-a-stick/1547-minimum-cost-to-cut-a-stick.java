class Solution {
    
        int help(int i,int j, int[] arr, int n, int[][] dp) {
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int mini = Integer.MAX_VALUE;
        for(int idx = i ;idx<=j;idx++){
         int cost = arr[j+1] - arr[i-1] + help(i,idx-1,arr,n,dp) + help(idx+1,j,arr,n,dp);

         mini = Math.min(cost,mini);
        }

        return dp[i][j] = mini;
    }
    public int minCost(int n, int[] cuts) {

        int[] arr = new int[cuts.length + 2];
        arr[0] = 0;
        for(int i=1;i<=cuts.length;i++){
           arr[i] = cuts[i-1];
        }
        arr[cuts.length+1] = n;
        Arrays.sort(arr);

         int[][] dp = new int[cuts.length+2][cuts.length+2];
        for(int[] a: dp){
            Arrays.fill(a,-1);
        }

        return help(1,cuts.length,arr,n,dp);
    }
}