class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character , Integer>mp = new HashMap<>();
        int r =0; int l=0; int ans =0;
        while(r < s.length()){
          char c = s.charAt(r);
          mp.put(c,mp.getOrDefault(c,0)+1);

          while(mp.get(c)>1 && l<r){
            char ch = s.charAt(l);
            mp.put(ch,mp.getOrDefault(ch,0)-1);
            if(mp.get(ch) == 0){
                mp.remove(ch);
            }
            l++;
          }

          if(mp.get(c)==1){
            ans = Math.max(ans, r-l+1);
          }
          r++;

        }

        return ans;
    }
}