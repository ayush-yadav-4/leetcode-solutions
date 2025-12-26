class Solution {
    int helper(int i,int j,int[][] dp,List<List<Integer>> grid){
      
        if(i == grid.size()-1){
            return grid.get(grid.size()-1).get(j);
        }
        if(i>grid.size()-1 || j > grid.get(i).size()-1 ) return 1_000_000_000;
        if(dp[i][j] != -1) return dp[i][j];
        
         
        int down = grid.get(i).get(j) + helper(i+1,j,dp,grid);
        int diag = grid.get(i).get(j) + helper(i+1,j+1,dp,grid);

        return dp[i][j] = Math.min(down,diag);
    }
    public int minimumTotal(List<List<Integer>> grid) {
        int[][] dp = new int[grid.size()+1][grid.size()+1];

        for(int[] arr : dp){
          Arrays.fill(arr,-1);
        }
        //return helper(0,0,dp,grid);
       
       for(int i =0;i<grid.get(grid.size()-1).size();i++){
           dp[grid.size()-1][i] = grid.get(grid.size()-1).get(i);
       }
        for(int i = grid.size()-2;i>=0;i--){
            for(int j = 0;j<grid.get(i).size();j++){
               int down = grid.get(i).get(j) +dp[i+1][j];
               int diag = grid.get(i).get(j) + dp[i+1][j+1];

               dp[i][j] = Math.min(down,diag);
            }
        }
        return dp[0][0];
    }
}