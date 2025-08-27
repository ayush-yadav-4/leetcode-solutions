class Solution {
    public static int helper(String text1, String text2,int idx1,int idx2,int[][]dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(text1.charAt(idx1) == text2.charAt(idx2)){
            return dp[idx1][idx2] = 1 + helper(text1,text2,idx1-1,idx2-1,dp);
        }
     return dp[idx1][idx2] =  Math.max(helper(text1,text2,idx1-1,idx2,dp),helper(text1,text2,idx1,idx2-1,dp));
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int [][] dp = new int[text1.length()+1][text2.length()+1];

        // for(int[] row: dp){
        //  Arrays.fill(row,-1);
        // }
        // return helper(text1,text2,text1.length()-1,text2.length()-1,dp);


        for(int i=0;i<=text1.length();i++){
           dp[i][0] = 0;
        }
         for(int i=0;i<=text2.length();i++){
           dp[0][i] = 0;
        }

        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
               if(text1.charAt(i-1) == text2.charAt(j-1)){
                 dp[i][j] = 1 + dp[i-1][j-1];
               }
               else {
                dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
               }
            }
        }
        return dp[text1.length()][text2.length()];
    }
}