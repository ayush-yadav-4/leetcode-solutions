class Solution {

   
    public String shortestCommonSupersequence(String s1, String s2) {
        int[][] dp = new int[s1.length()+1][s2.length()+1];
        for(int[]a : dp){
            Arrays.fill(a,0);
        }
        int i=0,j=0;
        for( i=0;i<s1.length();i++){
            for( j=0;j<s2.length();j++){
               
               if(s1.charAt(i) == s2.charAt(j)){
                dp[i+1][j+1]= 1 + dp[i][j];
               }
               else dp[i+1][j+1]=Math.max( dp[i+1][j],dp[i][j+1] );
            }
        }
        StringBuilder ans = new StringBuilder();
     
        while(i>0 && j>0){
          if(s1.charAt(i-1) == s2.charAt(j-1)){
            ans.append(s1.charAt(i-1));
            i--; j--;
          }
          else if(dp[i-1][j] > dp[i][j-1]){
             ans.append(s1.charAt(i-1));
             i--;
          }
          else{
            ans.append(s2.charAt(j-1));
             j--;
          }
        }

        while(i>0){
           ans.append(s1.charAt(i-1));
             i--;
        }
        while(j>0){
          ans.append(s2.charAt(j-1));
             j--;
        }

        return ans.reverse().toString();
    }
}