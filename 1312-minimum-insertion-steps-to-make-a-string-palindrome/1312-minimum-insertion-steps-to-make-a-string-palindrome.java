class Solution {
    public int minInsertions(String s) {
        
          int[][] dp = new int[s.length()+2][s.length()+2];
        
        for(int[] a: dp){
            Arrays.fill(a,-1);
        }
        String s2 = new StringBuilder(s).reverse().toString();

        for(int i=0;i<s.length();i++){
          dp[0][i] = 0;
        }
        for(int i=0;i<s.length();i++){
          dp[i][0] = 0;
        }
        int ans = 0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++){
                if(s.charAt(i) == s2.charAt(j)){
                    dp[i+1][j+1] = 1 + dp[i][j];
                   
                }
                else dp[i+1][j+1] = Math.max(dp[i+1][j] , dp[i][j+1]);
            }
        }

        return (s.length() - dp[s.length()][s.length()]);
    }
}