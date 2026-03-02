class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character , Integer>mp = new HashMap<>();
        int r =0; int l=0; int ans =0;
        while(r < s.length()){
          char c = s.charAt(r);
         // mp.put(c,mp.getOrDefault(c,0)+1);

         if(mp.containsKey(c) == true){
            l = Math.max(l,mp.get(c)+1);
         }
         mp.put(c,r);
         ans = Math.max(ans, r-l+1);

        //   if(mp.get(c)==1){
        //     ans = Math.max(ans, r-l+1);
        //   }
          r++;

        }

        return ans;
    }
}