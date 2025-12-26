class Solution {
    int helper(int i , int j1,int j2,int[][][] dp, int[][] grid){
        
        if(i>=grid.length || j1<0 || j1>=grid[0].length || j2<0 || j2>=grid[0].length){
            return -1_000_000_000;
        }

        if(i == grid.length-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
          int[] d = {-1,0,+1};
        int ans = Integer.MIN_VALUE;
        for(int a = 0;a<3;a++){
            for(int b=0;b<3;b++){
                  if(j1 == j2){
                     ans = Math.max(ans,(grid[i][j1] + helper(i+1,j1 + d[a],j2 + d[b],dp,grid)));
                  }
                  else{
                    ans = Math.max(ans,(grid[i][j1]+grid[i][j2] + helper(i+1,j1 + d[a],j2 + d[b],dp,grid)));
                  }
            }
        }

        return dp[i][j1][j2] = ans;
    }
    public int cherryPickup(int[][] grid) {
        int[][][] dp = new int[grid.length][grid[0].length][grid[0].length];

        for(int[][] arr: dp){
             for(int[]arr2:arr){
                Arrays.fill(arr2,-1);
             }
        }

         return helper(0,0,grid[0].length-1,dp,grid);
    }
}