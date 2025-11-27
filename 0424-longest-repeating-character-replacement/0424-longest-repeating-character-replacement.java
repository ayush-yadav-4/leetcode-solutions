class Solution {
    int check(int[] freq){
        int cnt = 0;
     for(int i=0;i<freq.length;i++){
       if(freq[i] > 0)cnt++;
     }

     return cnt;
    }
    public int characterReplacement(String s, int k) {
        int[] hash = new int[26];

        Arrays.fill(hash , 0);
        int st = 0,end = 0, ans = 0,maxfreq = 0;
        while(end < s.length()){
            hash[s.charAt(end) - 'A']++;
            maxfreq = Math.max(maxfreq,hash[s.charAt(end) - 'A']);
            int len = end - st + 1;

            while((len - maxfreq) > k && st<= end){
              hash[s.charAt(st) - 'A']--;
              st++;
              maxfreq = Math.max(maxfreq,hash[s.charAt(end) - 'A']);
             len = end - st + 1;
            }

            ans  = Math.max(ans, end - st +1);
            end++;

        }

        return ans;
    }
}