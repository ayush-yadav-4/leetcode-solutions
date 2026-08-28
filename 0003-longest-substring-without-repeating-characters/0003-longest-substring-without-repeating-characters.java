class Solution {
    public int lengthOfLongestSubstring(String s) {
       
       Map<Character, Integer> mp = new HashMap<>();
       int ans = 0,i=0,j=0;
        while(i<s.length()){
          mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i),0)+1);

          while(mp.get(s.charAt(i)) > 1 && i > j){
            mp.put(s.charAt(j), mp.get(s.charAt(j)) - 1);
            if(mp.get(s.charAt(j)) == 0){
                mp.remove(s.charAt(j));
            }
            j++;
          }
          ans = Math.max(ans, (i-j+1));
          i++;
        }

    return ans;
    }
}