class Solution {

    int help(int i, int j , String s, String t, int[][]dp){
      if( j == t.length()) return s.length() - i;
      if(i == s.length()){
        if(j!=t.length())return t.length() - j;

        return 0;
      }

      if (dp[i][j] != -1) return dp[i][j];
      if(s.charAt(i) == t.charAt(j)){
        return dp[i][j] = help(i+1, j+1,s,t,dp);
      }

      return dp[i][j] = 1 + Math.min(help(i+1,j+1,s,t,dp), Math.min(help(i+1,j,s,t,dp),help(i,j+1,s,t,dp)));
    }
    public int minDistance(String s, String t) {
        int[][] dp = new int[s.length()+1][t.length()+1];

        for(int[] a: dp){
        Arrays.fill(a,-1);
        }

        return help(0,0,s,t,dp);

        // for(int i=0;i<=s.length();i++){
        //   dp[i][0] = i; 
        // }
        //  for(int j=0;j<=t.length();j++){
        //   dp[0][j] = j; 
        // }

        // for(int i=1;i<=s.length();i++){
        //     for(int j=1;j<=t.length();j++){
              
        //       if(s.charAt(i-1) == t.charAt(j-1)){
        //         dp[i][j] = dp[i-1][j-1]; 
        //       }
        //       else{
        //         dp[i][j] = 1 + Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1]));
        //       }
        //     }
        // }

        // return dp[s.length()][t.length()];

    }
}