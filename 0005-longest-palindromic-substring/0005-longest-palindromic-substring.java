class Solution {
    public String longestPalindrome(String s) {
        if(s.length() == 0 || s.length() == 1) return s;
        boolean[][]dp = new boolean[s.length()][s.length()];
          int maxlen =1,st = 0; 
        for(int i=0;i<s.length();i++){
           dp[i][i] = true;
        }

        for(int i=0;i<s.length()-1;i++){
            if(s.charAt(i) == s.charAt(i+1)){
                dp[i][i+1] = true;
                st = i;
                maxlen = 2;
            }
        }

        for(int len = 3;len<=s.length();len++){
            for(int i=0;i<=s.length()-len;i++){
                int j = i + len-1;
              if(s.charAt(i) == s.charAt(j) && dp[i+1][j-1]){
                dp[i][j] = true;
                st = i;
                maxlen = len;
              }
            }
        }

        return s.substring(st,st+maxlen);
    }
}