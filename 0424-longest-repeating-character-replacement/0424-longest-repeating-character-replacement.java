class Solution {
   
    public int characterReplacement(String s, int k) {
       
       int r = 0, l = 0, ans = 0, maxf = 0;
       int[] hash = new int[26];
       while(r<s.length()){
          hash[s.charAt(r) - 'A']++;
          maxf = Math.max(maxf,hash[s.charAt(r) - 'A']);

          while(((r-l+1) - maxf) > k){
            hash[s.charAt(l) - 'A']--;
            maxf = 0;
            for(int i=0;i<=25;i++){
               maxf = Math.max(maxf,hash[i]);
            }
            l++;
          }
         if(((r-l+1) - maxf) <= k){
            ans = Math.max(ans,r-l+1 );
         }
         r++;


       }

       return ans;
    }
}