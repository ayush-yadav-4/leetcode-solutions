class Solution {
    long help(int i, int j , String s, String t, long[][] dp){
     if(j<0) return 1;
     if(i<0) return 0;
    

     if(dp[i][j] != -1) return dp[i][j];

     if(s.charAt(i) == t.charAt(j)){
        return dp[i][j] = help(i-1,j-1,s,t,dp) + help(i-1,j,s,t,dp);
     }
     return  dp[i][j] = help(i-1,j,s,t,dp);
    } 
    public int numDistinct(String s, String t) {
        long[][] dp = new long[s.length()][t.length()];

        for(long[] a: dp){
        Arrays.fill(a,-1);
        }

        return (int)help(s.length()-1,t.length()-1,s,t,dp);
    }
}