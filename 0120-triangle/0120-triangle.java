class Solution {
    int help(int n , int m ,  int[][] dp, List<List<Integer>> grid){
        if(n == grid.size()-1){
            return grid.get(n).get(m);
        }
        if(n>=grid.size() || m >= grid.get(n).size() ){
            return Integer.MAX_VALUE;
        }
        if(dp[n][m] != -1) return dp[n][m];

        int down = help(n+1,m,dp,grid);
        int diag = help(n+1,m+1,dp,grid);
        return dp[n][m] = grid.get(n).get(m) + Math.min(down, diag);
        
        
    }
    public int minimumTotal(List<List<Integer>> grid) {
       int[][] dp = new int[grid.size()][grid.get(grid.size()-1).size()];

       for(int[] arr: dp){
         Arrays.fill(arr,-1);
       }

       // return help(0,0,dp,grid);
       int n = grid.size();
       int m = grid.get(n-1).size();
        for(int i=0;i<grid.get(n-1).size();i++){
           dp[n-1][i] = grid.get(n-1).get(i);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
              dp[i][j] = grid.get(i).get(j) + Math.min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
}