class Solution {
    public int lengthOfLongestSubstring(String s) {
       Map<Character, Integer>mp = new HashMap<>();
       int ans =0, r=0,l=0;
       while(r<s.length()){
          mp.put(s.charAt(r), mp.getOrDefault(s.charAt(r),0)+1);

          while(l<r && mp.get(s.charAt(r)) > 1 ){
            mp.put(s.charAt(l), mp.get(s.charAt(l))-1);
            if(mp.get(s.charAt(l)) == 0){
                mp.remove(s.charAt(l));
            }
            l++;
          }

          ans = Math.max(ans, r-l+1);
          r++;
       }
       return ans;


    }
}