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
      // return help(text1.length()-1,text2.length()-1,text1,text2,dp);
       for(int idx1 = 0;idx1<text1.length();idx1++){
         dp[idx1][0] = 0;
       }
       for(int idx1 = 0;idx1<text2.length();idx1++){
         dp[0][idx1] = 0;
       }
       for(int i = 0;i<text1.length();i++){
         for(int j = 0;j<text2.length();j++){
             if(text1.charAt(i) == text2.charAt(j)){
                dp[i+1][j+1] = 1 + dp[i][j];
             }

             else dp[i+1][j+1] = Math.max(dp[i][j+1], dp[i+1][j]);
         } 
       }

       if(dp[text1.length()][text2.length()] == -1)return 0;
       return dp[text1.length()][text2.length()];
      
    }
}