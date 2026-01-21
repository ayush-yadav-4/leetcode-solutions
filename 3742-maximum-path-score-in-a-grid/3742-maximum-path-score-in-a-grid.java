class Solution {
    int helper(int i, int j , int k ,int[][] grid, int[][][] dp){
         if(k<0) return Integer.MIN_VALUE/2;
        if(i==0 && j ==0){
              if (grid[0][0] != 0 && k == 0) return Integer.MIN_VALUE/2;;
            return dp[i][j][k] = grid[0][0];
        }
     
        
        if(i<0 || j < 0) return  Integer.MIN_VALUE/2;

        if(dp[i][j][k]!= -1) return dp[i][j][k];
        int val = grid[i][j];
        int nk = k;
        if(val != 0)nk = k-1;
        int up =  helper(i-1,j,nk,grid,dp);
        int right =  helper(i,j-1,nk,grid,dp);
        int maxi =  Math.max(up, right);
        if(maxi<0) return dp[i][j][k] = Integer.MIN_VALUE/2;
    return dp[i][j][k] = val + maxi;
   
    }
    public int maxPathScore(int[][] grid, int k) {
        //if(k == 0) return 0;
        int[][][] dp= new int[grid.length+1][grid[0].length+1][k+1];

        
        for(int a[][] : dp){
           for(int b[] : a){
            Arrays.fill(b,-1);
        }
        }
     int ans=  helper(grid.length-1,grid[0].length-1,k,grid,dp);
       
        if(ans<0) return -1;
        return ans;
    }
}