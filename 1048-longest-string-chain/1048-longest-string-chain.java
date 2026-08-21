class Solution {

    boolean check(String l, String s){
        if(l.length() != s.length()+1 ) return false;

        int i=0; int j = 0;

        while(j<l.length() && i< s.length()){
         if(l.charAt(j) == s.charAt(i))i++;

         j++;
        }

        return s.length() == i;
    }
    public int longestStrChain(String[] words) {
        
        int[] dp = new int[words.length];
        
        Arrays.fill(dp,1);
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        int maxi = 0;
        for(int i=0;i<words.length;i++){
            for(int j=0;j<i;j++){
                if(check(words[i], words[j])){
                  dp[i] =Math.max(dp[i], dp[j] +1);
                  
                 
                }
            }
             maxi = Math.max(maxi, dp[i]);
        }
         if(maxi == 0) return 1;
         return maxi;

    }
}