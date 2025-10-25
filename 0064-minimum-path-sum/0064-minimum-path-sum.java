class Solution {

    int helper(int[][] arr,int m,int n,int[][]dp){
        if(m<0 || n < 0) return (int)1e7;
        if(m==0 && n ==0) return arr[0][0];

        if(dp[m][n] != -1 ) return dp[m][n];

        int up = arr[m][n] + helper(arr,m-1,n,dp);
        int left = arr[m][n] + helper(arr,m,n-1,dp);

        return dp[m][n] = Math.min(left , up);
    }
    public int minPathSum(int[][] grid) {
       
        int[][]dp = new int[grid.length][grid[0].length];

        for(int[] a: dp){
            Arrays.fill(a,-1);
        }
        return helper(grid,grid.length-1,grid[0].length-1,dp);
    }
}