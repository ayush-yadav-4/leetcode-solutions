class Solution {

    int helper(int[][] arr,int m,int n,int[][]dp){
        if(m<0 || n < 0) return 0;
        if(m==0 && n == 0){
            return 1;
        }
        if(arr[m][n] == 1) return 0;
        

        if(dp[m][n] != -1) return dp[m][n];

        int up = helper(arr,m-1,n,dp);
        int left = helper(arr,m,n-1,dp);

        return dp[m][n] = up + left;
    }
    public int uniquePathsWithObstacles(int[][] arr) {

        if(arr[0][0] == 1 || arr[arr.length-1][arr[0].length-1] == 1) return 0;
        int[][]dp = new int[arr.length][arr[0].length];

        for(int[] a: dp){
            Arrays.fill(a,-1);
        }
        return helper(arr,arr.length-1,arr[0].length-1,dp);

    }
}