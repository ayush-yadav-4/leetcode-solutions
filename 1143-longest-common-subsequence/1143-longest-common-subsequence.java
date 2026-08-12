class Solution {

    int help(int idx1, int idx2,String s1, String s2, int[][] dp){
       if(idx1 < 0 || idx2 < 0) return 0;


       if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

       if(s1.charAt(idx1) == s2.charAt(idx2)){
        return dp[idx1][idx2] = 1 + help(idx1-1,idx2-1,s1,s2,dp);
       }
       return dp[idx1][idx2] = Math.max(help(idx1-1,idx2,s1,s2,dp),help(idx1,idx2-1,s1,s2,dp));

    }
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length()+1][text2.length()+1];

        for(int[] a: dp){
         Arrays.fill(a,-1);
        }
       return help(text1.length()-1,text2.length()-1,text1,text2,dp);
      
    }
}