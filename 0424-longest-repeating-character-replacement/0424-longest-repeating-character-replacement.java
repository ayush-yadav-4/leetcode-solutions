class Solution {
    public int characterReplacement(String s, int k) {
        
        int[] hash = new int[26];
        Arrays.fill(hash,0);
        int ans = 0,st=0,end=0,maxfreq=0;
        while(end < s.length()){
           hash[s.charAt(end) - 'A']++;
           maxfreq = Math.max(maxfreq, hash[s.charAt(end) - 'A']);

           while(((end-st+1) - maxfreq) > k){
              hash[s.charAt(st) - 'A']--;
              maxfreq = 0;
              for(int i=0;i<26;i++){ maxfreq = Math.max(maxfreq,hash[i]);}
              st++;
           }

           if((end-st+1) - maxfreq <=k){
            ans = Math.max(ans,end-st+1);
           }
           end++;
        }
        return ans;
    }
}